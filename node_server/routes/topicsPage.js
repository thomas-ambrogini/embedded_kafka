var express = require("express");
var router = express.Router();

// const topics = require("topicData");


const topics = [
  { name: "Topic 1", messages: ["Message 1", "Message 2"] },
  {
    name: "Topic 2",
    messages: [
      "Message 3",
      "Message 4",
      "Message 233242",
      "jfdlakfj",
      "dlksjfjsl",
      "dslfjfljsdlf",
      "dsfjklsd",
      "sldjsljf",
      "dskfds",
      "dsjkflsldjf",
      "djkslflsf",
    ],
  },
  { name: "Topic 3", messages: ["Helloooooo"] },
  // Add more topics and messages as needed
];

const topicPairs = [];
for (let i = 0; i < topics.length; i += 2) {
  const pair = [topics[i], topics[i + 1]];
  topicPairs.push(pair);
}

/* GET home page. */
router.get("/", function (req, res, next) {
  //res.render("topics_page", { title: "Embedded Kafka", topicPairs })
  res.render("webSocketProva");
});

module.exports = router;
