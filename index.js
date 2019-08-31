import Lexer from './js/lex/Lexer.js'
import Parser from './js/parser/Parser.js'

let codeEl = document.querySelector('#code')
let tokenEl = document.querySelector('#token')
let astEl = document.querySelector('#ast')
codeEl.addEventListener('input', () => {
  token()
})
token()
function token () {
  let code = codeEl.value
  let lexer = new Lexer(code)
  let tokens = lexer.getTokens()
  console.table(tokens)
  let parser = new Parser(tokens)
  let ast = parser.expression()

  console.log(ast)
  let el = syncDOM(ast)

  tokenEl.innerHTML = tokens.map(item => JSON.stringify(item)).join('<br/>')
  astEl.firstChild && astEl.firstChild.remove()
  astEl.appendChild(el)
}
function syncDOM (node) {
  let el = document.createElement('div')
  if (node.token) {
    el.innerHTML = '[' + node.token.type + '] '+ node.token.text
  } else {
    el.innerHTML = '[' + node.operand + ']'
  }
  if (node.left) {
    el.appendChild(syncDOM(node.left))
  }
  if (node.right) {
    el.appendChild(syncDOM(node.right))
  }
  return el
}
