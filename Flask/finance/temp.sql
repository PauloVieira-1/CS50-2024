CREATE TABLE "transactions"
(
    id               INTEGER PRIMARY KEY,
    user             TEXT    NOT NULL,
    symbol          TEXT NOT NULL,
    stock_price           INTEGER NOT NULL,
    date            INTEGER NOT NULL DEFAULT current_timestamp
);
