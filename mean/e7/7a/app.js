const express = require("express");
const app = express();
const things = require("./route");
app.use("/things", things);
app.listen(8000, "127.0.0.1", () => {
  console.log("Server is running on http://127.0.0.1:8000");
});
