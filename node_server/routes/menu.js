var express = require("express");
var router = express.Router();

const pages = [
  { title: "Home", url: "/" },
  { title: "Create Topics", url: "/topicForm" },
  { title: "Topics Page", url: "/topicsPage" },
];

/* GET menu page. */
router.get("/", function (req, res, next) {
  res.render("menu", { title: "Embedded Kafka", pages });
});

module.exports = router;
