// Generated by BUCKLESCRIPT VERSION 4.0.0, PLEASE EDIT WITH CARE
'use strict';

var Jest = require("@glennsl/bs-jest/src/jest.js");
var Curry = require("bs-platform/lib/js/curry.js");
var BignumberJs = require("bignumber.js");

function todo() {
  return Jest.pass;
}

function tableTests1(label, fn, rows) {
  return Jest.testAll(label, rows, (function (param) {
                return Jest.Expect[/* toBe */2](param[1], Jest.Expect[/* expect */0](Curry._1(fn, param[0])));
              }));
}

function tableTests2(label, fn, rows) {
  return Jest.testAll(label, rows, (function (param) {
                return Jest.Expect[/* toBe */2](param[2], Jest.Expect[/* expect */0](Curry._2(fn, param[0], param[1])));
              }));
}

function thenString(fn, bn) {
  return Curry._1(fn, bn).toString();
}

function expectString(bn, str) {
  return Jest.Expect[/* toBe */2](str, Jest.Expect[/* expect */0](bn.toString()));
}

describe("Construction", (function () {
        Jest.test("fromString", (function () {
                return expectString(new BignumberJs("100"), "100");
              }));
        Jest.test("fromFloat", (function () {
                return expectString(new BignumberJs(100), "100");
              }));
        return Jest.test("fromInt", (function () {
                      return expectString(new BignumberJs(100), "100");
                    }));
      }));

var two = new BignumberJs(2);

var three = new BignumberJs(3);

var ten = new BignumberJs(10);

var twenty = new BignumberJs(20);

describe("Operations", (function () {
        Jest.test("plus", (function () {
                return expectString(ten.plus(ten), "20");
              }));
        Jest.test("plusFloat", (function () {
                return expectString(ten.plus(10), "20");
              }));
        Jest.test("plusInt", (function () {
                return expectString(ten.plus(10), "20");
              }));
        Jest.test("minus", (function () {
                return expectString(ten.minus(ten), "0");
              }));
        Jest.test("minusFloat", (function () {
                return expectString(ten.minus(10), "0");
              }));
        Jest.test("minusInt", (function () {
                return expectString(ten.minus(10), "0");
              }));
        Jest.test("times", (function () {
                return expectString(ten.times(ten), "100");
              }));
        Jest.test("timesFloat", (function () {
                return expectString(ten.times(10), "100");
              }));
        Jest.test("timesInt", (function () {
                return expectString(ten.times(10), "100");
              }));
        Jest.test("div", (function () {
                return expectString(ten.div(two), "5");
              }));
        Jest.test("divFloat", (function () {
                return expectString(ten.div(2), "5");
              }));
        Jest.test("divInt", (function () {
                return expectString(ten.div(2), "5");
              }));
        Jest.test("idiv", (function () {
                return expectString(ten.idiv(new BignumberJs("9")), "1");
              }));
        Jest.test("idivFloat", (function () {
                return expectString(ten.idiv(9), "1");
              }));
        Jest.test("idivInt", (function () {
                return expectString(ten.idiv(9), "1");
              }));
        Jest.test("mod_", (function () {
                return expectString(ten.mod(three), "1");
              }));
        Jest.test("modFloat", (function () {
                return expectString(ten.mod(3), "1");
              }));
        Jest.test("modInt", (function () {
                return expectString(ten.mod(3), "1");
              }));
        Jest.test("pow", (function () {
                return expectString(new BignumberJs("3").pow(new BignumberJs("2")), "9");
              }));
        Jest.test("powFloat", (function () {
                return expectString(new BignumberJs(3).pow(2), "9");
              }));
        return Jest.test("powInt", (function () {
                      return expectString(new BignumberJs(3).pow(2), "9");
                    }));
      }));

describe("Comparisons", (function () {
        Jest.test("eq", (function () {
                return Jest.Expect[/* toBe */2](true, Jest.Expect[/* expect */0](ten.eq(ten)));
              }));
        Jest.test("eqFloat", (function () {
                return Jest.Expect[/* toBe */2](true, Jest.Expect[/* expect */0](ten.eq(10)));
              }));
        Jest.test("eqInt", (function () {
                return Jest.Expect[/* toBe */2](true, Jest.Expect[/* expect */0](ten.eq(10)));
              }));
        tableTests2("gt", (function (prim, prim$1) {
                return prim.gt(prim$1);
              }), /* :: */[
              /* tuple */[
                ten,
                two,
                true
              ],
              /* :: */[
                /* tuple */[
                  two,
                  ten,
                  false
                ],
                /* :: */[
                  /* tuple */[
                    ten,
                    ten,
                    false
                  ],
                  /* [] */0
                ]
              ]
            ]);
        tableTests2("gtFloat", (function (prim, prim$1) {
                return prim.gt(prim$1);
              }), /* :: */[
              /* tuple */[
                ten,
                2,
                true
              ],
              /* :: */[
                /* tuple */[
                  two,
                  10,
                  false
                ],
                /* :: */[
                  /* tuple */[
                    ten,
                    10,
                    false
                  ],
                  /* [] */0
                ]
              ]
            ]);
        tableTests2("gtInt", (function (prim, prim$1) {
                return prim.gt(prim$1);
              }), /* :: */[
              /* tuple */[
                ten,
                2,
                true
              ],
              /* :: */[
                /* tuple */[
                  two,
                  10,
                  false
                ],
                /* :: */[
                  /* tuple */[
                    ten,
                    10,
                    false
                  ],
                  /* [] */0
                ]
              ]
            ]);
        tableTests2("gte", (function (prim, prim$1) {
                return prim.gte(prim$1);
              }), /* :: */[
              /* tuple */[
                ten,
                ten,
                true
              ],
              /* :: */[
                /* tuple */[
                  two,
                  ten,
                  false
                ],
                /* [] */0
              ]
            ]);
        tableTests2("gtFloat", (function (prim, prim$1) {
                return prim.gte(prim$1);
              }), /* :: */[
              /* tuple */[
                ten,
                10,
                true
              ],
              /* :: */[
                /* tuple */[
                  two,
                  10,
                  false
                ],
                /* [] */0
              ]
            ]);
        tableTests2("gtInt", (function (prim, prim$1) {
                return prim.gte(prim$1);
              }), /* :: */[
              /* tuple */[
                ten,
                10,
                true
              ],
              /* :: */[
                /* tuple */[
                  two,
                  10,
                  false
                ],
                /* [] */0
              ]
            ]);
        tableTests2("lt", (function (prim, prim$1) {
                return prim.lt(prim$1);
              }), /* :: */[
              /* tuple */[
                ten,
                two,
                false
              ],
              /* :: */[
                /* tuple */[
                  two,
                  ten,
                  true
                ],
                /* :: */[
                  /* tuple */[
                    ten,
                    ten,
                    false
                  ],
                  /* [] */0
                ]
              ]
            ]);
        tableTests2("ltFloat", (function (prim, prim$1) {
                return prim.lt(prim$1);
              }), /* :: */[
              /* tuple */[
                ten,
                2,
                false
              ],
              /* :: */[
                /* tuple */[
                  two,
                  10,
                  true
                ],
                /* :: */[
                  /* tuple */[
                    ten,
                    10,
                    false
                  ],
                  /* [] */0
                ]
              ]
            ]);
        tableTests2("ltInt", (function (prim, prim$1) {
                return prim.lt(prim$1);
              }), /* :: */[
              /* tuple */[
                ten,
                2,
                false
              ],
              /* :: */[
                /* tuple */[
                  two,
                  10,
                  true
                ],
                /* :: */[
                  /* tuple */[
                    ten,
                    10,
                    false
                  ],
                  /* [] */0
                ]
              ]
            ]);
        tableTests2("lte", (function (prim, prim$1) {
                return prim.lte(prim$1);
              }), /* :: */[
              /* tuple */[
                ten,
                ten,
                true
              ],
              /* :: */[
                /* tuple */[
                  two,
                  ten,
                  true
                ],
                /* [] */0
              ]
            ]);
        tableTests2("ltFloat", (function (prim, prim$1) {
                return prim.lte(prim$1);
              }), /* :: */[
              /* tuple */[
                ten,
                10,
                true
              ],
              /* :: */[
                /* tuple */[
                  two,
                  10,
                  true
                ],
                /* [] */0
              ]
            ]);
        return tableTests2("ltInt", (function (prim, prim$1) {
                      return prim.lte(prim$1);
                    }), /* :: */[
                    /* tuple */[
                      ten,
                      10,
                      true
                    ],
                    /* :: */[
                      /* tuple */[
                        two,
                        10,
                        true
                      ],
                      /* [] */0
                    ]
                  ]);
      }));

describe("Instance methods", (function () {
        Jest.test("abs", (function () {
                return expectString(new BignumberJs("-1").abs(), "1");
              }));
        Jest.test("integerValue", (function () {
                return expectString(new BignumberJs("123.456").integerValue(), "123");
              }));
        tableTests1("isInteger", (function (prim) {
                return prim.isInteger();
              }), /* :: */[
              /* tuple */[
                new BignumberJs(1),
                true
              ],
              /* :: */[
                /* tuple */[
                  new BignumberJs(1.5),
                  false
                ],
                /* [] */0
              ]
            ]);
        tableTests1("isNaN", (function (prim) {
                return prim.isNaN();
              }), /* :: */[
              /* tuple */[
                new BignumberJs(1),
                false
              ],
              /* :: */[
                /* tuple */[
                  new BignumberJs("test"),
                  true
                ],
                /* [] */0
              ]
            ]);
        tableTests1("isNegative", (function (prim) {
                return prim.isNegative();
              }), /* :: */[
              /* tuple */[
                new BignumberJs(1),
                false
              ],
              /* :: */[
                /* tuple */[
                  new BignumberJs(-1),
                  true
                ],
                /* [] */0
              ]
            ]);
        tableTests1("isPositive", (function (prim) {
                return prim.isPositive();
              }), /* :: */[
              /* tuple */[
                new BignumberJs(1),
                true
              ],
              /* :: */[
                /* tuple */[
                  new BignumberJs(-1),
                  false
                ],
                /* [] */0
              ]
            ]);
        tableTests1("isZero", (function (prim) {
                return prim.isZero();
              }), /* :: */[
              /* tuple */[
                new BignumberJs(1),
                false
              ],
              /* :: */[
                /* tuple */[
                  new BignumberJs(0),
                  true
                ],
                /* [] */0
              ]
            ]);
        tableTests1("negated", (function (param) {
                return param.negated().toString();
              }), /* :: */[
              /* tuple */[
                new BignumberJs(1),
                "-1"
              ],
              /* :: */[
                /* tuple */[
                  new BignumberJs(-1),
                  "1"
                ],
                /* [] */0
              ]
            ]);
        Jest.test("shiftedBy", (function () {
                return expectString(new BignumberJs(1234).shiftedBy(-2), "12.34");
              }));
        return Jest.test("sqrt", (function () {
                      return expectString(new BignumberJs(16).sqrt(), "4");
                    }));
      }));

describe("String representation", (function () {
        return Jest.test("toExponential", (function () {
                      return Jest.Expect[/* toBe */2]("4.56e+1", Jest.Expect[/* expect */0](new BignumberJs(45.6).toExponential()));
                    }));
      }));

exports.todo = todo;
exports.tableTests1 = tableTests1;
exports.tableTests2 = tableTests2;
exports.thenString = thenString;
exports.expectString = expectString;
exports.two = two;
exports.three = three;
exports.ten = ten;
exports.twenty = twenty;
/*  Not a pure module */