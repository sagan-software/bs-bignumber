type t;

type base = int;

[@bs.deriving jsConverter]
type rm =
  | [@bs.as 0] RoundUp
  | [@bs.as 1] RoundDown
  | [@bs.as 2] RoundCeil
  | [@bs.as 3] RoundFloor
  | [@bs.as 4] RoundHalfUp
  | [@bs.as 5] RoundHalfDown
  | [@bs.as 6] RoundHalfEven
  | [@bs.as 7] RoundHalfCeil
  | [@bs.as 8] RoundHalfFloor
  | [@bs.as 9] Euclid;

module Format = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    decimalSeparator: string,
    [@bs.optional]
    groupSeparator: string,
    [@bs.optional]
    groupSize: int,
    [@bs.optional]
    secondaryGroupSize: int,
    [@bs.optional]
    fractionGroupSeparator: string,
    [@bs.optional]
    fractionGroupSize: int,
  };
};

module Config = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "DECIMAL_PLACES"]
    decimalPlaces: int,
    [@bs.optional] [@bs.as "ROUNDING_MODE"]
    roundingMode: int,
    [@bs.optional] [@bs.as "EXPONENTIAL_AT"]
    exponentialAt: int,
    [@bs.optional] [@bs.as "EXPONENTIAL_AT"]
    exponentialAtArray: array(int),
    [@bs.optional] [@bs.as "RANGE"]
    range: int,
    [@bs.optional] [@bs.as "RANGE"]
    rangeArray: array(int),
    [@bs.optional] [@bs.as "CRYPTO"]
    crypto: bool,
    [@bs.optional] [@bs.as "MODULO_MODE"]
    moduloMode: rm,
    [@bs.optional] [@bs.as "POW_PRECISION"]
    powPrecision: int,
    [@bs.optional] [@bs.as "FORMAT"]
    format: Format.t,
    [@bs.optional] [@bs.as "ALPHABET"]
    alphabet: string,
  };
};

[@bs.module "bignumber.js/bignumber.js"]
external config_ : Config.t => unit = "config";

let config =
    (
      ~decimalPlaces=?,
      ~roundingMode=?,
      ~exponentialAt=?,
      ~exponentialAtArray=?,
      ~range=?,
      ~rangeArray=?,
      ~crypto=?,
      ~moduloMode=?,
      ~powPrecision=?,
      ~alphabet=?,
      ~decimalSeparator=".",
      ~groupSeparator=",",
      ~groupSize=3,
      ~secondaryGroupSize=0,
      ~fractionGroupSeparator=" ",
      ~fractionGroupSize=0,
      (),
    ) => {
  let format =
    Format.t(
      ~decimalSeparator,
      ~groupSeparator,
      ~groupSize,
      ~secondaryGroupSize,
      ~fractionGroupSeparator,
      ~fractionGroupSize,
      (),
    );
  let cfg =
    Config.t(
      ~decimalPlaces?,
      ~roundingMode?,
      ~exponentialAt?,
      ~exponentialAtArray?,
      ~range?,
      ~rangeArray?,
      ~crypto?,
      ~moduloMode?,
      ~powPrecision?,
      ~alphabet?,
      ~format,
      (),
    );
  config_(cfg);
};

[@bs.module "bignumber.js/bignumber.js"]
external isBigNumber : 'any => bool = "";
[@bs.module "bignumber.js/bignumber.js"] external random : unit => t = "";
[@bs.module "bignumber.js/bignumber.js"] external randomDp : int => t = "";

/* Maximum */
[@bs.module "bignumber.js/bignumber.js"] [@bs.splice]
external max : array(t) => t = "";
[@bs.module "bignumber.js/bignumber.js"] external max2 : (t, t) => t = "max";
[@bs.module "bignumber.js/bignumber.js"]
external max3 : (t, t, t) => t = "max";
[@bs.module "bignumber.js/bignumber.js"]
external max4 : (t, t, t, t) => t = "max";
[@bs.module "bignumber.js/bignumber.js"]
external max5 : (t, t, t, t, t) => t = "max";
[@bs.module "bignumber.js/bignumber.js"]
external max6 : (t, t, t, t, t, t) => t = "max";

/* Minimum */
[@bs.module "bignumber.js/bignumber.js"] [@bs.splice]
external min : array(t) => t = "";
[@bs.module "bignumber.js/bignumber.js"] external min2 : (t, t) => t = "min";
[@bs.module "bignumber.js/bignumber.js"]
external min3 : (t, t, t) => t = "min";
[@bs.module "bignumber.js/bignumber.js"]
external min4 : (t, t, t, t) => t = "min";
[@bs.module "bignumber.js/bignumber.js"]
external min5 : (t, t, t, t, t) => t = "min";
[@bs.module "bignumber.js/bignumber.js"]
external min6 : (t, t, t, t, t, t) => t = "min";

/* Construction */
[@bs.module] [@bs.new]
external fromString : string => t = "bignumber.js/bignumber.js";
[@bs.module] [@bs.new]
external fromFloat : float => t = "bignumber.js/bignumber.js";
[@bs.module] [@bs.new]
external fromInt : int => t = "bignumber.js/bignumber.js";

/* Addition */
[@bs.send] external plus : (t, t) => t = "";
[@bs.send] external plusBase : (t, t, base) => t = "plus";
[@bs.send] external plusFloat : (t, float) => t = "plus";
[@bs.send] external plusFloatBase : (t, float, base) => t = "plus";
[@bs.send] external plusInt : (t, int) => t = "plus";
[@bs.send] external plusIntBase : (t, int, base) => t = "plus";

/* Subtraction */
[@bs.send] external minus : (t, t) => t = "";
[@bs.send] external minusBase : (t, t, base) => t = "minus";
[@bs.send] external minusFloat : (t, float) => t = "minus";
[@bs.send] external minusFloatBase : (t, float, base) => t = "minus";
[@bs.send] external minusInt : (t, int) => t = "minus";
[@bs.send] external minusIntBase : (t, int, base) => t = "minus";

/* Multiplication */
[@bs.send] external times : (t, t) => t = "";
[@bs.send] external timesBase : (t, t, base) => t = "times";
[@bs.send] external timesFloat : (t, float) => t = "times";
[@bs.send] external timesFloatBase : (t, float, base) => t = "times";
[@bs.send] external timesInt : (t, int) => t = "times";
[@bs.send] external timesIntBase : (t, int, base) => t = "times";

/* Division */
[@bs.send] external div : (t, t) => t = "";
[@bs.send] external divBase : (t, t, base) => t = "div";
[@bs.send] external divFloat : (t, float) => t = "div";
[@bs.send] external divFloatBase : (t, float, base) => t = "div";
[@bs.send] external divInt : (t, int) => t = "div";
[@bs.send] external divIntBase : (t, int, base) => t = "div";

/* Integer division */
[@bs.send] external idiv : (t, t) => t = "";
[@bs.send] external idivBase : (t, t, base) => t = "idiv";
[@bs.send] external idivFloat : (t, float) => t = "idiv";
[@bs.send] external idivFloatBase : (t, float, base) => t = "idiv";
[@bs.send] external idivInt : (t, int) => t = "idiv";
[@bs.send] external idivIntBase : (t, int, base) => t = "idiv";

/* Modulo */
[@bs.send] external mod_ : (t, t) => t = "mod";
[@bs.send] external modBase : (t, t, base) => t = "mod";
[@bs.send] external modFloat : (t, float) => t = "mod";
[@bs.send] external modFloatBase : (t, float, base) => t = "mod";
[@bs.send] external modInt : (t, int) => t = "mod";
[@bs.send] external modIntBase : (t, int, base) => t = "mod";

/* Exponents */
[@bs.send] external pow : (t, t) => t = "";
[@bs.send] external powMod : (t, t, int) => t = "pow";
[@bs.send] external powFloat : (t, float) => t = "pow";
[@bs.send] external powFloatMod : (t, float, int) => t = "pow";
[@bs.send] external powInt : (t, int) => t = "pow";
[@bs.send] external powIntMod : (t, int, int) => t = "pow";

/* Equal */
[@bs.send] external eq : (t, t) => bool = "";
[@bs.send] external eqBase : (t, t, base) => bool = "eq";
[@bs.send] external eqFloat : (t, float) => bool = "eq";
[@bs.send] external eqFloatBase : (t, float, base) => bool = "eq";
[@bs.send] external eqInt : (t, int) => bool = "eq";
[@bs.send] external eqIntBase : (t, int, base) => bool = "eq";

/* Less than */
[@bs.send] external lt : (t, t) => bool = "";
[@bs.send] external ltBase : (t, t, base) => bool = "lt";
[@bs.send] external ltFloat : (t, float) => bool = "lt";
[@bs.send] external ltFloatBase : (t, float, base) => bool = "lt";
[@bs.send] external ltInt : (t, int) => bool = "lt";
[@bs.send] external ltIntBase : (t, int, base) => bool = "lt";

/* Less than or equal to */
[@bs.send] external lte : (t, t) => bool = "";
[@bs.send] external lteBase : (t, t, base) => bool = "lte";
[@bs.send] external lteFloat : (t, float) => bool = "lte";
[@bs.send] external lteFloatBase : (t, float, base) => bool = "lte";
[@bs.send] external lteInt : (t, int) => bool = "lte";
[@bs.send] external lteIntBase : (t, int, base) => bool = "lte";

/* Greater than */
[@bs.send] external gt : (t, t) => bool = "";
[@bs.send] external gtBase : (t, t, base) => bool = "gt";
[@bs.send] external gtFloat : (t, float) => bool = "gt";
[@bs.send] external gtFloatBase : (t, float, base) => bool = "gt";
[@bs.send] external gtInt : (t, int) => bool = "gt";
[@bs.send] external gtIntBase : (t, int, base) => bool = "gt";

/* Greater than or equal to */
[@bs.send] external gte : (t, t) => bool = "";
[@bs.send] external gteBase : (t, t, base) => bool = "gte";
[@bs.send] external gteFloat : (t, float) => bool = "gte";
[@bs.send] external gteFloatBase : (t, float, base) => bool = "gte";
[@bs.send] external gteInt : (t, int) => bool = "gte";
[@bs.send] external gteIntBase : (t, int, base) => bool = "gte";

/* Instance methods */
[@bs.send] external abs : t => t = "";

/* Decimal places */
[@bs.send] external getDecimalPlaces : t => int = "decimalPlaces";
[@bs.send] external setDecimalPlaces : (t, int) => t = "decimalPlaces";
[@bs.send] external setDecimalPlacesRm : (t, int, rm) => t = "decimalPlaces";

/* Precision / Significant Digits */
[@bs.send] external getPrecision : t => int = "precision";
[@bs.send] external setPrecision : (t, int) => t = "precision";
[@bs.send] external setPrecisionRm : (t, int, rm) => t = "precision";
[@bs.send]
external setPrecisionTrue : (t, [@bs.as {json|true|json}] _) => t =
  "precision";

/* Integer value */
[@bs.send] external integerValue : t => t = "";
[@bs.send] external integerValueRm : (t, rm) => t = "";

[@bs.send] external isFinite : t => bool = "";
[@bs.send] external isInteger : t => bool = "";
[@bs.send] external isNaN : t => bool = "";
[@bs.send] external isNegative : t => bool = "";
[@bs.send] external isPositive : t => bool = "";
[@bs.send] external isZero : t => bool = "";
[@bs.send] external negated : t => t = "";
[@bs.send] external shiftedBy : (t, int) => t = "";
[@bs.send] external sqrt : t => t = "sqrt";

/* To exponential string */
[@bs.send] external toExponential : t => string = "";
[@bs.send] external toExponentialDp : (t, int) => string = "toExponential";
[@bs.send]
external toExponentialRm : (t, [@bs.as {json|null|json}] _, rm) => string =
  "toExponential";
[@bs.send]
external toExponentialDpRm : (t, int, rm) => string = "toExponential";

/* To fixed string */
[@bs.send] external toFixed : t => string = "";
[@bs.send] external toFixedDp : (t, int) => string = "toFixed";
[@bs.send]
external toFixedRm : (t, [@bs.as {json|null|json}] _, int) => string =
  "toFixed";
[@bs.send] external toFixedDpRm : (t, int, int) => string = "toFixed";

/* To formatted string */
[@bs.send] external toFormat : t => string = "toFormat";
[@bs.send] external toFormatDp : (t, int) => string = "toFormat";
[@bs.send]
external toFormatRm : (t, [@bs.as {json|null|json}] _, int) => string =
  "toFormat";
[@bs.send] external toFormatDpRm : (t, int, int) => string = "toFormat";

/* To fraction string */
[@bs.send] external toFraction : t => (string, string) = "";
[@bs.send] external toFractionMax : (t, int) => (string, string) = "";

/* To string */
[@bs.send] external toString : t => string = "";
[@bs.send] external toStringBase : (t, int) => string = "";

[@bs.send] external toFloat : t => float = "toNumber";

/* Compared to */
[@bs.send] external comparedTo_ : t => Js.Nullable.t(int) = "comparedTo";
[@bs.send]
external comparedToBase_ : (t, base) => Js.Nullable.t(int) = "comparedTo";
let comparedTo = t =>
  t |. comparedTo_ |. Js.Nullable.toOption |. Belt.Option.getWithDefault(0);
let comparedToBase = (t, base) =>
  t
  |. comparedToBase_(base)
  |. Js.Nullable.toOption
  |. Belt.Option.getWithDefault(0);

/* JSON */
let decodeString = Json.Decode.string |> Json.Decode.map(fromString);
let decodeInt = Json.Decode.(int |> map(fromInt));
let decodeFloat = Json.Decode.(Json.Decode.float |> map(fromFloat));
let decode = Json.Decode.(oneOf([decodeString, decodeInt, decodeFloat]));
[@bs.send] external toJson : t => string = "toJSON";
let encode = d => d |> toJson |> Json.Encode.string;
