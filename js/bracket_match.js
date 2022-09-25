/** checks if bracket in str match
  @param  str - string - expression with brakets
  @return 1 - match
          0 - not match
*/
function is_bracket_match(str) { 

  const re = /([\(\)])/g;
  const brackets = str.match(re);
 
  console.log({brackets})
  if(brackets == undefined) //null)
    return 0;  
  if(brackets[0] === ')')
    return 0;

  let nesting_level = 0;  
  for(let i = 0; i < brackets.length; i++){
    //console.log(brackets[i]);
    if(brackets[i] == '(')
      nesting_level++;    
    else 
      nesting_level--;    
  }
  console.log({nesting_level}); 
  return nesting_level === 0 ? 1 : 0;

}   


const tests = [
  ["(let x = 10; i < (y); (i++))", 1],
  [")(let x = 10; i < (y); (i++))", 0],
  ["(let x = 10; i < (y); (i++)", 0],
  ["(let x = 10; i < ((y); (i++))", 0],
  ["a bcd e f(", 0],
  ["a bcd e f", 0],
];
let test_pass = 0;
let test_fail = 0;
for(let i = 0; i < tests.length; i++){
  if(is_bracket_match(tests[i][0]) === tests[i][1] ){
    console.log("test pass");
    test_pass++;
  }
  else{
    console.log("test fail");
    test_fail++;
  } 
}
console.log({test_pass});
console.log({test_fail});

