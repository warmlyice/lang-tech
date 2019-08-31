import Lexer from './js/lex/Lexer.js'
import Parser from './js/parser/Parser.js'

let el = document.querySelector('#code')
let tokenEl = document.querySelector('#token')
el.addEventListener('input', () => {
  token()
})
token()
function token () {
  let code = el.value
  let lexer = new Lexer(code)
  let tokens = lexer.getTokens()
  console.table(tokens)
  let parser = new Parser(tokens)
  let ast = parser.getAST()
  console.log(ast)

  tokenEl.innerHTML = tokens.map(item => JSON.stringify(item)).join('<br/>')
}
