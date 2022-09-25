/** checks if bracket in str match
  @param  str - string - expression with brakets
  @return 1 - match
          0 - not match
*/
function is_bracket_match(str) { 

  const re = /([\(\)])/g;
  const brackets = str.match(re);
  
  let nesting_level = 0;  
  for(let i = 0;
      i < ( brackets ? brackets.length : 0 ); 
      i++){
    console.log(brackets[i]);
    if(brackets[i] == '('){
      nesting_level++;
    }
    else{
      nesting_level--;
    }
  }
  
  return nesting_level > 0 ? 0 : 1;

}   


const tests = [
  ["(let x = 10; i < (y); (i++))", 1],
  ["(let x = 10; i < (y); (i++)", 0],
  ["(let x = 10; i < ((y); (i++))", 0],
  ["a bcd e f(", 0],
  ["a bcd e f", 0],
];
for(let i = 0; i < tests.length; i++){
  console.log(is_bracket_match(tests[i][0]) === tests[i][1] );
}
