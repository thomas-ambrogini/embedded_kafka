// public/js/client.js

document.addEventListener("DOMContentLoaded", () => {
  var socket = io(); // Connect to the Socket.io server

  // Handle incoming file content updates
  socket.on("fileContent", function (data) {
    // Display the file content in a <pre> element
    document.getElementById("file-content").textContent = data;
  });
});
