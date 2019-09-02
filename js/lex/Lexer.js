import isDigital from './isDigital.js'
import isWhitespace from './isWhitespace.js'
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
    this.skipWhitespace()
    let t = this.nextToken()
    while (t.type !== TokenType.EOF) {
      this.tokens.push(t)
      this.skipWhitespace()
      t = this.nextToken()
    }
    this.tokens.push(t)
  }
  skipWhitespace () {
    while (isWhitespace(this.ch)) {
      this.start = this.start + 1
      this.current = this.current + 1
      this.ch = this.sourceText[this.current]
    }
  }
  nextToken () {
    let t
    switch (this.ch) {
      case undefined:
        t = new Token(TokenType.EOF)
        break
      case '(':
        t = new Token(TokenType.LEFT_PAREN, '(')
        break
      case ')':
        t = new Token(TokenType.RIGHT_PAREN, ')')
        break
      case '*':
        // TODO *=
        t = new Token(TokenType.STAR, '*')
        break
      case '/':
        t = new Token(TokenType.SLASH, '/')
        break
      case '+':
        t = new Token(TokenType.PLUS, '+')
        break
      case '-':
        t = new Token(TokenType.MINUS, '-')
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
      this.ch = undefined
      return this.ch
    }
    this.ch = this.sourceText[this.current]
    return this.ch
  }
}
