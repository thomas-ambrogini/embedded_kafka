var express = require("express");
var router = express.Router();

const fs = require("fs");
const topics = require("topicData");
const topicsJSONFile = "../build/conf/topics.json";

const topicNames = [];

/*POST home page. */
router.post("/", function (req, res, next) {
  const topicName = req.body.topic;
  var objName = {
    name: topicName,
  };
  topics.push(objName);
  fs.writeFileSync(topicsJSONFile, JSON.stringify(topics, null, 2), "utf-8");
  res.render("created_topic", { topicName });
});

module.exports = router;
