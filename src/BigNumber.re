type t;

/* Construction */
[@bs.module] [@bs.new] external fromString : string => t = "bignumber.js";
[@bs.module] [@bs.new] external fromFloat : float => t = "bignumber.js";
[@bs.module] [@bs.new] external fromInt : int => t = "bignumber.js";

/* Addition */
[@bs.send] external plus : (t, t) => t = "";
[@bs.send] external plusFloat : (t, float) => t = "plus";
[@bs.send] external plusInt : (t, int) => t = "plus";

/* Subtraction */
[@bs.send] external minus : (t, t) => t = "";
[@bs.send] external minusFloat : (t, float) => t = "minus";
[@bs.send] external minusInt : (t, int) => t = "minus";

/* Multiplication */
[@bs.send] external times : (t, t) => t = "";
[@bs.send] external timesFloat : (t, float) => t = "times";
[@bs.send] external timesInt : (t, int) => t = "times";

/* Division */
[@bs.send] external div : (t, t) => t = "";
[@bs.send] external divFloat : (t, float) => t = "div";
[@bs.send] external divInt : (t, int) => t = "div";

/* Integer division */
[@bs.send] external idiv : (t, t) => t = "";
[@bs.send] external idivFloat : (t, float) => t = "idiv";
[@bs.send] external idivInt : (t, int) => t = "idiv";

/* Modulo */
[@bs.send] external mod_ : (t, t) => t = "mod";
[@bs.send] external modFloat : (t, float) => t = "mod";
[@bs.send] external modInt : (t, int) => t = "mod";

/* Exponents */
[@bs.send] external pow : (t, t) => t = "";
[@bs.send] external powFloat : (t, float) => t = "pow";
[@bs.send] external powInt : (t, int) => t = "pow";

/* Equal */
[@bs.send] external eq : (t, t) => bool = "";
[@bs.send] external eqFloat : (t, float) => bool = "eq";
[@bs.send] external eqInt : (t, int) => bool = "eq";

/* Less than */
[@bs.send] external lt : (t, t) => bool = "";
[@bs.send] external ltFloat : (t, float) => bool = "lt";
[@bs.send] external ltInt : (t, int) => bool = "lt";

/* Less than or equal to */
[@bs.send] external lte : (t, t) => bool = "";
[@bs.send] external lteFloat : (t, float) => bool = "lte";
[@bs.send] external lteInt : (t, int) => bool = "lte";

/* Greater than */
[@bs.send] external gt : (t, t) => bool = "";
[@bs.send] external gtFloat : (t, float) => bool = "gt";
[@bs.send] external gtInt : (t, int) => bool = "gt";

/* Greater than or equal to */
[@bs.send] external gte : (t, t) => bool = "";
[@bs.send] external gteFloat : (t, float) => bool = "gte";
[@bs.send] external gteInt : (t, int) => bool = "gte";

/* Instance methods */
[@bs.send] external abs : t => t = "";
[@bs.send] external integerValue : t => t = "";
[@bs.send] external isFinite : t => bool = "";
[@bs.send] external isInteger : t => bool = "";
[@bs.send] external isNaN : t => bool = "";
[@bs.send] external isNegative : t => bool = "";
[@bs.send] external isPositive : t => bool = "";
[@bs.send] external isZero : t => bool = "";
[@bs.send] external negated : t => t = "";
[@bs.send] external shiftedBy : (t, int) => t = "";
[@bs.send] external sqrt : t => t = "sqrt";

[@bs.send] external toFloat : t => float = "toNumber";

/* String representation */
[@bs.send] external toExponential : t => string = "";
[@bs.send] external toFixed : t => string = "";
[@bs.send] external toFormat : t => string = "";
[@bs.send] external toFraction : t => (string, string) = "";
[@bs.send] external toJson : t => string = "toJSON";
[@bs.send] external toString : t => string = "";

/* JSON */
let decodeString = Json.Decode.string |> Json.Decode.map(fromString);
let decodeInt = Json.Decode.(int |> map(fromInt));
let decodeFloat = Json.Decode.(Json.Decode.float |> map(fromFloat));
let decode = Json.Decode.(oneOf([decodeString, decodeInt, decodeFloat]));
let encode = d => d |> toJson |> Json.Encode.string;
