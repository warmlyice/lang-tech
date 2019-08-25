import Lexer from './lex/Lexer.js'

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

  tokenEl.innerHTML = tokens.map(item => JSON.stringify(item)).join('<br/>')
}
