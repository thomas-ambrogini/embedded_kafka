var express = require("express");
var router = express.Router();

const fs = require("fs");
const topics = require("topicData");
const topicsJSONFile = "../build/conf/topics.json";

/*POST home page. */
router.post("/", function (req, res, next) {
  const topicName = req.body.topic;
  topics.push(topicName);
  const jsonObj = topics.map((item) => ({ name: item }));
  fs.writeFileSync(topicsJSONFile, JSON.stringify(jsonObj, null, 2), "utf-8");
  res.render("created_topic", { topicName });
});

module.exports = router;
