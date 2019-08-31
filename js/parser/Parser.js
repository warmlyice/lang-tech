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
  addition () {
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
  match (type) {
    if (this.tokens[this.current].type === type) {
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
