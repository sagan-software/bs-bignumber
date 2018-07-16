open Jest;
open Expect;
open! Expect.Operators;
open BigNumber;

let todo = () => pass;

let tableTests1 = (label, fn, rows) =>
  testAll(label, rows, ((n1, expected)) =>
    n1 |. fn |> expect |> toBe(expected)
  );

let tableTests2 = (label, fn, rows) =>
  testAll(label, rows, ((n1, n2, expected)) =>
    n1 |. fn(n2) |> expect |> toBe(expected)
  );

let thenString = (fn, bn) => bn |> fn |> toString;

let expectString = (bn, str) => bn |> toString |> expect |> toBe(str);

describe("Construction", () => {
  test("fromString", () =>
    "100" |> fromString |. expectString("100")
  );
  test("fromFloat", () =>
    100. |> fromFloat |. expectString("100")
  );
  test("fromInt", () =>
    100 |> fromInt |. expectString("100")
  );
});

let two = 2 |> fromInt;
let three = 3 |> fromInt;
let ten = 10 |> fromInt;
let twenty = 20 |> fromInt;

describe("Operations", () => {
  test("plus", () =>
    ten |. plus(ten) |. expectString("20")
  );
  test("plusFloat", () =>
    ten |. plusFloat(10.) |. expectString("20")
  );
  test("plusInt", () =>
    ten |. plusInt(10) |. expectString("20")
  );

  test("minus", () =>
    ten |. minus(ten) |. expectString("0")
  );
  test("minusFloat", () =>
    ten |. minusFloat(10.) |. expectString("0")
  );
  test("minusInt", () =>
    ten |. minusInt(10) |. expectString("0")
  );

  test("times", () =>
    ten |. times(ten) |. expectString("100")
  );
  test("timesFloat", () =>
    ten |. timesFloat(10.) |. expectString("100")
  );
  test("timesInt", () =>
    ten |. timesInt(10) |. expectString("100")
  );

  test("div", () =>
    ten |. div(two) |. expectString("5")
  );
  test("divFloat", () =>
    ten |. divFloat(2.) |. expectString("5")
  );
  test("divInt", () =>
    ten |. divInt(2) |. expectString("5")
  );

  test("idiv", () =>
    ten |. idiv("9" |> fromString) |. expectString("1")
  );
  test("idivFloat", () =>
    ten |. idivFloat(9.) |. expectString("1")
  );
  test("idivInt", () =>
    ten |. idivInt(9) |. expectString("1")
  );

  test("mod_", () =>
    ten |. mod_(three) |. expectString("1")
  );
  test("modFloat", () =>
    ten |. modFloat(3.) |. expectString("1")
  );
  test("modInt", () =>
    ten |. modInt(3) |. expectString("1")
  );

  test("pow", () =>
    "3" |> fromString |. pow("2" |> fromString) |. expectString("9")
  );
  test("powFloat", () =>
    3. |> fromFloat |. powFloat(2.) |. expectString("9")
  );
  test("powInt", () =>
    3 |> fromInt |. powInt(2) |. expectString("9")
  );
});

describe("Comparisons", () => {
  test("eq", () =>
    ten |. eq(ten) |> expect |> toBe(true)
  );
  test("eqFloat", () =>
    ten |. eqFloat(10.) |> expect |> toBe(true)
  );
  test("eqInt", () =>
    ten |. eqInt(10) |> expect |> toBe(true)
  );

  tableTests2(
    "gt",
    gt,
    [(ten, two, true), (two, ten, false), (ten, ten, false)],
  );
  tableTests2(
    "gtFloat",
    gtFloat,
    [(ten, 2., true), (two, 10., false), (ten, 10., false)],
  );
  tableTests2(
    "gtInt",
    gtInt,
    [(ten, 2, true), (two, 10, false), (ten, 10, false)],
  );

  tableTests2("gte", gte, [(ten, ten, true), (two, ten, false)]);
  tableTests2("gtFloat", gteFloat, [(ten, 10., true), (two, 10., false)]);
  tableTests2("gtInt", gteInt, [(ten, 10, true), (two, 10, false)]);

  tableTests2(
    "lt",
    lt,
    [(ten, two, false), (two, ten, true), (ten, ten, false)],
  );
  tableTests2(
    "ltFloat",
    ltFloat,
    [(ten, 2., false), (two, 10., true), (ten, 10., false)],
  );
  tableTests2(
    "ltInt",
    ltInt,
    [(ten, 2, false), (two, 10, true), (ten, 10, false)],
  );

  tableTests2("lte", lte, [(ten, ten, true), (two, ten, true)]);
  tableTests2("ltFloat", lteFloat, [(ten, 10., true), (two, 10., true)]);
  tableTests2("ltInt", lteInt, [(ten, 10, true), (two, 10, true)]);
});

describe("Instance methods", () => {
  test("abs", () =>
    "-1" |> fromString |> abs |. expectString("1")
  );

  test("integerValue", () =>
    "123.456" |> fromString |> integerValue |. expectString("123")
  );

  tableTests1(
    "isInteger",
    isInteger,
    [(1 |> fromInt, true), (1.5 |> fromFloat, false)],
  );

  tableTests1(
    "isNaN",
    isNaN,
    [(1 |> fromInt, false), ("test" |> fromString, true)],
  );

  tableTests1(
    "isNegative",
    isNegative,
    [(1 |> fromInt, false), ((-1) |> fromInt, true)],
  );

  tableTests1(
    "isPositive",
    isPositive,
    [(1 |> fromInt, true), ((-1) |> fromInt, false)],
  );

  tableTests1(
    "isZero",
    isZero,
    [(1 |> fromInt, false), (0 |> fromInt, true)],
  );

  tableTests1(
    "negated",
    negated |. thenString,
    [(1 |> fromInt, "-1"), ((-1) |> fromInt, "1")],
  );

  test("shiftedBy", () =>
    1234 |> fromInt |. shiftedBy(-2) |. expectString("12.34")
  );

  test("sqrt", () =>
    16 |> fromInt |. sqrt |. expectString("4")
  );
});

describe("String representation", () =>
  test("toExponential", () =>
    45.6 |> fromFloat |> toExponential |> expect |> toBe("4.56e+1")
  )
);
