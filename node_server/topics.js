const fs = require("fs");
const handlebars = require("handlebars");

const topics = ["topic1", "topic2", "topic3", "topic4"];

fs.readFile("topics-template.hbs", "utf8", (err, templateHtml) => {
  if (err) {
    console.error("Error reading template:", err);
    return;
  }

  const template = handlebars.compile(templateHtml);

  const data = { topics };

  const renderedHtml = template(data);

  console.log(renderedHtml);
});
