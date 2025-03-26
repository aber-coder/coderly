const express = require("express");
const app = express();
const things = require("./route");
app.use("/things", things);
app.listen(8000, "localhost", () => {
  console.log("Server is running on http://localhost:8000");
});
