import TokenType from '../lex/TokenType.js'
import ExprLiteral from './ExprLiteral.js'
import ExprBinary from './ExprBinary.js'


class Parser {
  constructor (tokens) {
    this.current = 0
    this.tokens = tokens
    this.ast = []
  }
  expression () {
    return this.addition()
  }
  /* 左递归(死循环)  -->  右递归(结合性) -->  EBNF循环( '+' NUMBER )*
   * ---------------------------------------
   expr           := addition
   addition       := multiplication ( '+' multiplication )*
   multiplication := NUMBER ( '+' NUMBER )*
   NUMBER         := [0-9]+
   * ---------------------------------------
   */
  addition () {
    let childLeft = this.multiplication()
    while (this.match([TokenType.PLUS, TokenType.MINUS])) {
      let operator = this.previous().text
      let childRight = this.multiplication()
      if (!childRight) {
        // throw new Error('syntax error: there should be token after "+"')
      }
      childLeft = new ExprBinary(operator, childLeft, childRight)
    }
    return childLeft
  }
  multiplication () {
    let childLeft = this.literal()
    while (this.match([TokenType.STAR, TokenType.SLASH])) {
      let operator = this.previous().text
      let childRight = this.literal()
      if (!childRight) {
        // throw new Error('syntax error: there should be token after "+"')
      }
      childLeft = new ExprBinary(operator, childLeft, childRight)
    }
    return childLeft
  }
  /* right recursive Associativity(结合性) 右结合，从右到左计算
   * ---------------------------------------
   expr     := addition
   addition := NUMBER | NUMBER '+' addition
   NUMBER   := [0-9]+
   * ---------------------------------------
   */
  additionRightRecursive () {
    let childLeft = this.literal()
    if (childLeft && this.match(TokenType.PLUS)) {
      childLeft = new ExprBinary('+', childLeft, this.addition())
    }
    return childLeft
  }
  literal () {
    let t = this.getToken()
    if (t.type === TokenType.NUMBER) {
      return new ExprLiteral(t)
    }
  }
  previous () {
    return this.tokens[this.current - 1]
  }
  match (type) {
    if (this.current > this.tokens.length - 1) return false
    let types = type
    if (!Array.isArray(type)) {
      types = [type]
    }
    if (types.indexOf(this.tokens[this.current].type) > -1) {
      this.current++
      return true
    }
  }
  getToken () {
    let t = this.tokens[this.current]
    this.current++
    return t
  }
  getAST () {
    return 'ast'
  }
}
export default Parser
