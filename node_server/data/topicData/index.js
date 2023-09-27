// topicData.js
const fs = require("fs");

const topicsJSONFile = "../build/conf/topics.json";

topicsString = fs.readFileSync(topicsJSONFile, { encoding: "utf8" });

var temp;

try {
    temp = JSON.parse(topicsString);
} catch(e) {
    temp = [];
}

const topics = temp;

module.exports = topics;
