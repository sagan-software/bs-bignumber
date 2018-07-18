open Jest;
open Expect;
open! Expect.Operators;
open BigNumber;

let todo = () => pass;

let thenString = (fn, bn) => bn |> fn |> toString;

let expectString = (bn, str) => bn |> toString |> expect |> toBe(str);

let zero = 0 |> fromInt;
let one = 1 |> fromInt;
let two = 2 |> fromInt;
let three = 3 |> fromInt;
let four = 4 |> fromInt;
let five = 5 |> fromInt;
let six = 6 |> fromInt;
let seven = 7 |> fromInt;
let eight = 8 |> fromInt;
let nine = 9 |> fromInt;
let ten = 10 |> fromInt;
let twenty = 20 |> fromInt;

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

describe("Maximum", () => {
  test("max", () =>
    [|one, ten, two, nine, three, eight, four, seven, five, six|]
    |. BigNumber.max
    |. expect
    |> toEqual(ten)
  );
  test("max2", () =>
    BigNumber.max2(two, four) |. expect |> toEqual(four)
  );
  test("max3", () =>
    BigNumber.max3(two, four, three) |. expect |> toEqual(four)
  );
  test("max4", () =>
    BigNumber.max4(two, four, three, five) |. expect |> toEqual(five)
  );
  test("max5", () =>
    BigNumber.max5(two, four, three, five, six) |. expect |> toEqual(six)
  );
  test("max6", () =>
    BigNumber.max6(two, four, three, five, six, seven)
    |. expect
    |> toEqual(seven)
  );
});

describe("Minimum", () => {
  test("min", () =>
    [|one, ten, two, nine, three, eight, four, seven, five, six|]
    |. BigNumber.min
    |. expect
    |> toEqual(one)
  );
  test("min2", () =>
    BigNumber.min2(two, four) |. expect |> toEqual(two)
  );
  test("min3", () =>
    BigNumber.min3(two, four, three) |. expect |> toEqual(two)
  );
  test("min4", () =>
    BigNumber.min4(two, four, three, five) |. expect |> toEqual(two)
  );
  test("min5", () =>
    BigNumber.min5(two, four, three, five, six) |. expect |> toEqual(two)
  );
  test("min6", () =>
    BigNumber.min6(two, four, three, five, six, seven)
    |. expect
    |> toEqual(two)
  );
});

describe("Addition", () => {
  test("plus", () =>
    ten |. plus(ten) |. expectString("20")
  );
  test("plusBase", () =>
    ten |. plusBase(ten, 5) |. expectString("15")
  );
  test("plusFloat", () =>
    ten |. plusFloat(10.) |. expectString("20")
  );
  test("plusFloatBase", () =>
    ten |. plusFloatBase(10., 5) |. expectString("15")
  );
  test("plusInt", () =>
    ten |. plusInt(10) |. expectString("20")
  );
  test("plusIntBase", () =>
    ten |. plusIntBase(10, 5) |. expectString("15")
  );
});

describe("Subtraction", () => {
  test("minus", () =>
    ten |. minus(ten) |. expectString("0")
  );
  test("minusBase", () =>
    ten |. minusBase(ten, 5) |. expectString("5")
  );
  test("minusFloat", () =>
    ten |. minusFloat(10.) |. expectString("0")
  );
  test("minusFloatBase", () =>
    ten |. minusFloatBase(10., 5) |. expectString("5")
  );
  test("minusInt", () =>
    ten |. minusInt(10) |. expectString("0")
  );
  test("minusIntBase", () =>
    ten |. minusIntBase(10, 5) |. expectString("5")
  );
});

describe("Multiplication", () => {
  test("times", () =>
    ten |. times(ten) |. expectString("100")
  );
  test("timesBase", () =>
    ten |. timesBase(ten, 5) |. expectString("50")
  );
  test("timesFloat", () =>
    ten |. timesFloat(10.) |. expectString("100")
  );
  test("timesFloatBase", () =>
    ten |. timesFloatBase(10., 5) |. expectString("50")
  );
  test("timesInt", () =>
    ten |. timesInt(10) |. expectString("100")
  );
  test("timesIntBase", () =>
    ten |. timesIntBase(10, 5) |. expectString("50")
  );
});

describe("Division", () => {
  test("div", () =>
    ten |. div(two) |. expectString("5")
  );
  test("divBase", () =>
    ten |. divBase(ten, 5) |. expectString("2")
  );
  test("divFloat", () =>
    ten |. divFloat(2.) |. expectString("5")
  );
  test("divFloatBase", () =>
    ten |. divFloatBase(10., 5) |. expectString("2")
  );
  test("divInt", () =>
    ten |. divInt(2) |. expectString("5")
  );
  test("divIntBase", () =>
    ten |. divIntBase(10, 5) |. expectString("2")
  );
});

describe("Integer division", () => {
  test("idiv", () =>
    ten |. idiv(nine) |. expectString("1")
  );
  test("idivBase", () =>
    ten |. idivBase(ten, 3) |. expectString("3")
  );
  test("idivFloat", () =>
    ten |. idivFloat(9.) |. expectString("1")
  );
  test("idivFloatBase", () =>
    ten |. idivFloatBase(10., 3) |. expectString("3")
  );
  test("idivInt", () =>
    ten |. idivInt(9) |. expectString("1")
  );
  test("idivIntBase", () =>
    ten |. idivIntBase(10, 3) |. expectString("3")
  );
});

describe("Modulo", () => {
  test("mod_", () =>
    ten |. mod_(three) |. expectString("1")
  );
  test("modBase", () =>
    ten |. modBase(four, 5) |. expectString("2")
  );
  test("modFloat", () =>
    ten |. modFloat(3.) |. expectString("1")
  );
  test("modFloatBase", () =>
    ten |. modFloatBase(4., 5) |. expectString("2")
  );
  test("modInt", () =>
    ten |. modInt(3) |. expectString("1")
  );
  test("modIntBase", () =>
    ten |. modIntBase(4, 5) |. expectString("2")
  );
});

describe("Exponents", () => {
  test("pow", () =>
    three |. pow(two) |. expectString("9")
  );
  test("powMod", () =>
    three |. powMod(two, 3) |. expectString("0")
  );
  test("powFloat", () =>
    3. |. fromFloat |. powFloat(2.) |. expectString("9")
  );
  test("powFloatMod", () =>
    three |. powFloatMod(2., 3) |. expectString("0")
  );
  test("powInt", () =>
    3 |. fromInt |. powInt(2) |. expectString("9")
  );
  test("powIntMod", () =>
    three |. powIntMod(2, 3) |. expectString("0")
  );
});

describe("Equal (==)", () => {
  test("eq", () =>
    ten |. eq(ten) |> expect |> toBe(true)
  );
  test("eqBase", () =>
    ten |. eqBase(twenty, 5) |> expect |> toBe(true)
  );
  test("eqFloat", () =>
    ten |. eqFloat(10.) |> expect |> toBe(true)
  );
  test("eqFloatBase", () =>
    ten |. eqFloatBase(20., 5) |> expect |> toBe(true)
  );
  test("eqInt", () =>
    ten |. eqInt(10) |> expect |> toBe(true)
  );
  test("eqIntBase", () =>
    ten |. eqIntBase(20, 5) |> expect |> toBe(true)
  );
});

let tableTests1 = (label, fn, rows) =>
  testAll(label, rows, ((n1, expected)) =>
    n1 |. fn |> expect |> toBe(expected)
  );

let tableTests2 = (label, fn, rows) =>
  testAll(label, rows, ((n1, n2, expected)) =>
    n1 |. fn(n2) |> expect |> toBe(expected)
  );

let tableTests3 = (label, fn, rows) =>
  testAll(label, rows, ((n1, n2, base, expected)) =>
    n1 |. fn(n2, base) |> expect |> toBe(expected)
  );

describe("Greater than (>)", () => {
  tableTests2(
    "gt",
    gt,
    [(ten, two, true), (two, ten, false), (ten, ten, false)],
  );
  tableTests3(
    "gtBase",
    gtBase,
    [(ten, two, 3, true), (two, ten, 3, false), (ten, ten, 3, true)],
  );
  tableTests2(
    "gtFloat",
    gtFloat,
    [(ten, 2., true), (two, 10., false), (ten, 10., false)],
  );
  tableTests3(
    "gtFloatBase",
    gtFloatBase,
    [(ten, 2., 3, true), (two, 2., 3, false), (ten, 10., 3, true)],
  );
  tableTests2(
    "gtInt",
    gtInt,
    [(ten, 2, true), (two, 10, false), (ten, 10, false)],
  );
  tableTests3(
    "gtIntBase",
    gtIntBase,
    [(ten, 2, 3, true), (two, 2, 3, false), (ten, 10, 3, true)],
  );
});

describe("Greater than or equal to (>=)", () => {
  tableTests2("gte", gte, [(ten, ten, true), (two, ten, false)]);
  tableTests3(
    "gteBase",
    gteBase,
    [(ten, ten, 3, true), (two, ten, 3, false)],
  );
  tableTests2("gtFloat", gteFloat, [(ten, 10., true), (two, 10., false)]);
  tableTests3(
    "gteFloatBase",
    gteFloatBase,
    [(ten, 10., 3, true), (two, 10., 3, false)],
  );
  tableTests2("gtInt", gteInt, [(ten, 10, true), (two, 10, false)]);
  tableTests3(
    "gteIntBase",
    gteIntBase,
    [(ten, 10, 3, true), (two, 10, 3, false)],
  );
});

describe("Less than (<)", () => {
  tableTests2(
    "lt",
    lt,
    [(ten, two, false), (two, ten, true), (ten, ten, false)],
  );
  tableTests3(
    "ltBase",
    ltBase,
    [(ten, two, 3, false), (two, ten, 3, true), (ten, ten, 3, false)],
  );
  tableTests2(
    "ltFloat",
    ltFloat,
    [(ten, 2., false), (two, 10., true), (ten, 10., false)],
  );
  tableTests3(
    "ltFloatBase",
    ltFloatBase,
    [(ten, 2., 3, false), (two, 10., 3, true), (ten, 10., 3, false)],
  );
  tableTests2(
    "ltInt",
    ltInt,
    [(ten, 2, false), (two, 10, true), (ten, 10, false)],
  );
  tableTests3(
    "ltIntBase",
    ltIntBase,
    [(ten, 2, 3, false), (two, 10, 3, true), (ten, 10, 3, false)],
  );
});

describe("Less than or equal to (<=)", () => {
  tableTests2("lte", lte, [(ten, ten, true), (two, ten, true)]);
  tableTests3(
    "lteBase",
    lteBase,
    [(ten, ten, 3, false), (two, ten, 3, true)],
  );
  tableTests2("lteFloat", lteFloat, [(ten, 10., true), (two, 10., true)]);
  tableTests3(
    "lteFloatBase",
    lteFloatBase,
    [(ten, 10., 3, false), (two, 10., 3, true)],
  );
  tableTests2("lteInt", lteInt, [(ten, 10, true), (two, 10, true)]);
  tableTests3(
    "lteIntBase",
    lteIntBase,
    [(ten, 10, 3, false), (two, 10, 3, true)],
  );
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

describe("Decimal places", () => {
  test("getDecimalPlaces", () =>
    1234.56
    |. BigNumber.fromFloat
    |. BigNumber.getDecimalPlaces
    |. expect
    |> toEqual(2)
  );
  test("setDecimalPlaces", () =>
    1234.56
    |. BigNumber.fromFloat
    |. BigNumber.setDecimalPlaces(1)
    |. BigNumber.toString
    |. expect
    |> toEqual("1234.6")
  );
  test("setDecimalPlacesRm", () =>
    1234.56
    |. BigNumber.fromFloat
    |. BigNumber.setDecimalPlacesRm(1, BigNumber.RoundDown)
    |. BigNumber.toString
    |. expect
    |> toEqual("1234.5")
  );
});

describe("To exponential", () =>
  test("toExponential", () =>
    45.6 |> fromFloat |> toExponential |> expect |> toBe("4.56e+1")
  )
);

describe("JSON", () => {
  test("decodeString", () =>
    "10" |> Js.Json.string |> decodeString |. expectString("10")
  );

  test("decodeFloat", () =>
    10. |> Js.Json.number |> decodeFloat |. expectString("10")
  );

  test("decodeInt", () =>
    10. |> Js.Json.number |> decodeInt |. expectString("10")
  );

  testAll(
    "decode",
    [
      ("10" |> Js.Json.string, "10"),
      (10. |> Js.Json.number, "10"),
      (10.5 |> Js.Json.number, "10.5"),
    ],
    ((j, str)) =>
    j |> decode |. expectString(str)
  );

  test("encode", () =>
    10 |> fromInt |> encode |> expect |> toBe(Js.Json.string("10"))
  );
});

describe("Config", () => {
  test("decimalPlaces", () => {
    BigNumber.config(~decimalPlaces=4, ());
    ten
    |. BigNumber.div(three)
    |. BigNumber.toString
    |. expect
    |> toEqual("3.3333");
  });

  test("exponentialAt", () => {
    BigNumber.config(~exponentialAt=2, ());
    123
    |. BigNumber.fromInt
    |. BigNumber.toString
    |. expect
    |> toEqual("1.23e+2");
  });

  test("exponentialAtArray", () => {
    BigNumber.config(~exponentialAtArray=[|(-7), 20|], ());
    0.000000123
    |. BigNumber.fromFloat
    |. BigNumber.toString
    |. expect
    |> toEqual("1.23e-7");
  });
});
