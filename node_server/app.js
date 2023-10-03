var createError = require("http-errors");
var express = require("express");
const exphbs = require('express-handlebars');
var path = require("path");
var cookieParser = require("cookie-parser");
var logger = require("morgan");

var app = express();

// Routers
var indexRouter = require("./routes/index");
var createTopicsRouter = require("./routes/createTopic");
var topicsPageRouter = require("./routes/topicsPage");
var homeRouter = require("./routes/home");

// view engine setup
var hbs = exphbs.create();
app.engine('handlebars', hbs.engine);
app.set('view engine', 'handlebars');
app.set("views", "./views");

// Define your menu items
const menuItems = [
  { menu_id: "menu-home", label: 'Home', url: '/home' },
  { menu_id: "menu-create-topics", label: 'Create Topic', url: '/createTopics' },
  { menu_id: "menu-show-topics", label: 'Topics Page', url: '/topicsPage' }
];

// Middleware to set common data
app.use((req, res, next) => {
  res.locals.menuItems = menuItems;
  next();
});

app.use(logger("dev"));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, "public")));

app.use("/", indexRouter);
app.use("/createTopics", createTopicsRouter);
app.use("/topicsPage", topicsPageRouter);
app.use("/home", homeRouter)

// catch 404 and forward to error handler
app.use(function (req, res, next) {
  next(createError(404));
});

// error handler
app.use(function (err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get("env") === "development" ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render("error");
});

module.exports = app;
