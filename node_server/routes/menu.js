var express = require("express");
var router = express.Router();

const pages = [
  { title: "Home", url: "/" },
  { title: "About Us", url: "/about" },
  { title: "Create Topics", url: "/topic_form" },
];

/* GET menu page. */
router.get("/", function (req, res, next) {
  res.render("menu", { title: "Embedded Kafka", pages });
});

module.exports = router;
