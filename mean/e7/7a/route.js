const express = require("express");
const router = express.Router();

router.get("/", (req, res) => {
  res.send("Things - get data");
});

router.post("/", (req, res) => {
  res.send("hello, got a post request");
});

module.exports = router;
