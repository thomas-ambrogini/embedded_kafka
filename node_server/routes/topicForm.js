var express = require("express");
var router = express.Router();

const topics = require("topicData");

/* GET home page. */
router.get("/", function (req, res, next) {
  res.render("topic_form", { title: "Embedded Kafka", topics });
});

module.exports = router;
