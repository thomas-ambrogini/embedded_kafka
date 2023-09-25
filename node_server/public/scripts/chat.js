// public/js/chat.js

document.addEventListener("DOMContentLoaded", () => {
  var socket = io(); // Connect to the Socket.io server

  // Handle incoming chat messages
  socket.on("chat message", function (msg) {
    var li = document.createElement("li");
    li.textContent = msg;
    document.getElementById("messages").appendChild(li);
  });

  // Handle form submission (sending a chat message)
  document.getElementById("chat-form").addEventListener("submit", function (e) {
    e.preventDefault();
    var messageInput = document.getElementById("message-input");
    var message = messageInput.value;

    // Emit a chat message event to the server
    socket.emit("chat message", message);

    // Clear the input field
    messageInput.value = "";
  });
});
