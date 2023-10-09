document.addEventListener("DOMContentLoaded", () => {
  const socket = io();

  socket.on("topicUpdate", function (data) {
    const { topicName, messages } = data;
    const topicBoxes = document.querySelectorAll(".topic-box");

    let topicBox;
    for (const box of topicBoxes) {
      const h2 = box.querySelector("h2");
      if (h2.textContent === topicName) {
        topicBox = box;
        break;
      }
    }

    if (topicBox) {
      console.log(topicBox);

      const messageList = topicBox.querySelector(".message-list");
      console.log(messageList);

      messages.forEach((message) => {
        const messageItem = document.createElement("li");
        messageItem.textContent = message;
        messageList.appendChild(messageItem);
      });
    }
  });

  // Function to handle errors
  socket.on("error", (error) => {
    console.error("Socket.IO Error:", error);
  });

  // Function to handle connection open
  socket.on("connect", () => {
    console.log("Socket.IO connection established");
  });
});
