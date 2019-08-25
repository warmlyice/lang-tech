import isDigital from './isDigital.js'
import Token from './Token.js'
import TokenType from './TokenType.js'

export default class Lexer {
  start = 0
  current = 0
  ch = ''
  sourceText = ''
  tokens = []
  constructor (code) {
    this.sourceText = code
    this.ch = this.sourceText[this.current]
    this.generateTokens()
  }
  getTokens () {
    return this.tokens
  }
  generateTokens () {
    let t = this.nextToken()
    while (t.type !== TokenType.EOF) {
      this.tokens.push(t)
      t = this.nextToken()
    }
  }
  nextToken () {
    let t
    switch (this.ch) {
      case TokenType.EOF:
        t = new Token(TokenType.EOF)
        break
      case '+':
        t = new Token(TokenType.PLUS, '+')
        break
      default:
        if (isDigital(this.ch)) {
          t = this.number()
        }
    }
    this.consume()
    this.start = this.current
    return t
  }
  number () {
    while (isDigital(this.peek())) {
      this.consume()
    }
    let text = this.sourceText.slice(this.start, this.current + 1)
    return new Token(TokenType.NUMBER, text)
  }
  peek () {
    return this.sourceText[this.current + 1]
  }
  consume () {
    this.current = this.current + 1
    if (this.current > this.sourceText.length - 1) {
      this.ch = TokenType.EOF
      return this.ch
    }
    this.ch = this.sourceText[this.current]
    return this.ch
  }
}
