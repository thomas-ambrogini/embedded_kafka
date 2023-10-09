const fs = require("fs");
var express = require("express");
var router = express.Router();
var socketApi = require("../socketApi");
var io = socketApi.io;
const topics = require("topicData");
const { diffChars } = require("diff");

const files = {};

function getTopicName(filename) {
  const parts = filename.split("/");
  return parts[1].replace(".txt", "");
}

function readFileDeleteContent(filename) {
  fs.readFile(filename, "utf8", (err, newContent) => {
    if (err) {
      console.error(`Error reading ${filename}:`, err);
      return;
    }

    const oldContent = files[filename] || "";
    console.log("The old content for the file was: " + oldContent);

    files[filename] = newContent;
    console.log("The new content of the file is: " + newContent);

    const differences = diffChars(oldContent, newContent);

    console.log(
      "The difference is: " + differences[differences.length - 1].value
    );

    const messages = differences[differences.length - 1].value
      .split("\n")
      .filter(Boolean);

    io.emit("topicUpdate", {
      topicName: getTopicName(filename),
      messages,
    });
  });
}

function monitor(filesToMonitor) {
  function watchFile(filepath) {
    if (!fs.existsSync(filepath)) {
      fs.writeFileSync(filepath, "", "utf-8");
      console.log("File created:", filepath);
    }
    fs.watchFile(filepath, { interval: 1000 }, (curr, prev) => {
      if (curr.mtime !== prev.mtime) {
        console.log(`File ${filepath} has been modified.`);
        // Add your logic here to handle the file change.
        readFileDeleteContent(filepath);
      }
    });
  }

  filesToMonitor.forEach((filepath) => {
    watchFile(filepath);
  });
}

/* GET home page. */
router.get("/", function (req, res, next) {
  const filesToMonitor = topics.map(
    (topic) => "monitor/" + topic.name + ".txt"
  );
  monitor(filesToMonitor);
  res.render("topics_page", { topics });
});

module.exports = router;
