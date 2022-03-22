await db.SortedSetAddAsync("srczset", new SortedSetEntry[]
{
    new("one",1),
    new("two", 2),
    new ("three", 3),
    new("four", 4)
});

var numInSet = await db.ExecuteAsync("ZRANGESTORE", "dstzset", "srczset", 2, -1);

Console.WriteLine((int)numInSet);

var range = await db.SortedSetRangeByRankAsync("dstzset");

foreach (var elem in range)
{
    Console.WriteLine((string)elem);
}
