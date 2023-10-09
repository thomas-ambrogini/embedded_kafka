var express = require("express");
var router = express.Router();
const fs = require("fs");
const bodyParser = require("body-parser");

const topics = require("topicData");

const topicsJSONFile = "../build/conf/topics.json";
const monitorPath = "./monitor/";

function updateTopics(names) {
  for (const obj2 of names) {
    // Check if the name in obj2 is not already present in array1
    if (!topics.some((obj1) => obj1.name === obj2.name)) {
      topics.push({ name: obj2.name });
    }
  }
}

router.get("/", (req, res) => {
  res.render("createTopic", { title: "Embedded Kafka" });
});

router.get("/readJson", (req, res) => {
  fs.readFile(topicsJSONFile, "utf8", (err, data) => {
    if (err) {
      console.error(err);
      res.status(500).json({ error: "Error reading names" });
      return;
    }
    const names = JSON.parse(data);
    res.json(names);
  });
});

router.post("/writeJson", (req, res) => {
  const newName = req.body.name;

  fs.readFile(topicsJSONFile, "utf8", (err, data) => {
    if (err) {
      console.error(err);
      res.status(500).json({ error: "Error reading names" });
      return;
    }

    const names = JSON.parse(data);
    names.push({ name: newName }); // Save names as objects

    updateTopics(names);

    fs.writeFile(topicsJSONFile, JSON.stringify(names), (err) => {
      if (err) {
        console.error(err);
        res.status(500).json({ error: "Error writing names" });
        return;
      }
      res.json({ success: true });
    });
  });
});

module.exports = router;
