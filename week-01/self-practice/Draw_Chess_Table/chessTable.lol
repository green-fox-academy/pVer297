Magyar leírás: http://nyelvek.inf.elte.hu/leirasok/LOLCODE/
Language Specifications: https://github.com/justinmeza/lolcode-spec/blob/master/v1.2/lolcode-spec-v1.2.md
Code Interpreter: https://repl.it/languages/lolcode

HAI 1.2
  HOW DUZ I drwChessTbl YR Size
    I HAS A i ITZ 1
    I HAS A first ITZ " "
    I HAS A second ITZ "#"
    IM IN YR LOOP UPPIN YR i TIL BOTH SAEM i AN SUM OF PRODUKT OF Size AN Size AN 1
      BOTH SAEM 0 AN MOD OF i AN 2, O RLY?
        YA RLY, VISIBLE first!
        NO WAI, VISIBLE second!
      OIC

      BOTH SAEM 0 AN MOD OF i AN Size, O RLY?
        YA RLY, VISIBLE ""
        BOTH SAEM 0 AN MOD OF Size AN 2, O RLY?
          YA RLY
            I HAS A temp ITZ first
            first R second
            second R temp
          OIC
      OIC
    IM OUTTA YR LOOP
    VISIBLE ""
  IF U SAY SO

  I HAS A NUM ITZ 0
  VISIBLE "Chess Table Drawer v1.0"
  VISIBLE "How big Chess table do you want:: "!
  GIMMEH NUM
  MAEK NUM NUMBR
  VISIBLE "Ok, so " NUM "x" NUM
  drwChessTbl NUM
KTHXBYE
