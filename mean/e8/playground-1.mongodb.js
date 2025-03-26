db.dropDatabase();
db.createCollection("users");
use("users");

db.getMongo().getDBs();

db.users.drop();
db.users.find();
db.getCollectionNames();

db.users.insertOne({
  name: "a",
  joinTime: Date.now(),
});

db.users.find();

db.users.insertMany([
  {
    name: "b",
    joinTime: Date.now(),
  },
  {
    name: "c",
    joinTime: Date.now(),
  },
]);

db.users.find();

db.users.update(
  {},
  {
    $rename: { joinTime: "joinedTime" },
  },
  { multi: true }
);

db.users.find();

db.users.remove({ name: "c" });
db.users.find();
