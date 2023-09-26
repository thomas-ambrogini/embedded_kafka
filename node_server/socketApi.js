var socketIo = require("socket.io");
var io = socketIo();
var socketApi = {};

socketApi.io = io;

io.on("connection", function (socket) {
  console.log("A user connected");
});

socketApi.sendNotification = function () {
  io.sockets.emit("hello", { msg: "Hello World!" });
};

module.exports = socketApi;
