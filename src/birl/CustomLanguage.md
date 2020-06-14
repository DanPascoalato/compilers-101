program := expect_statement .

expect_statement = 
   "val" ident = literal
   | "def" ident "(" {args} ")" block
   | "if" condition block 
   | "print" "(" literal ")"
   | "exit"

block = "{" expect_statement*  "}"
    
condition = 
    "!" expression |
    expression ("==" | "!=") expression
    
expression = ["+"|"-"] term { ("+"|"-"|) term }

term = factor  { ("*"|"/") factor }

factor = var | literal | "(" expression ")"
