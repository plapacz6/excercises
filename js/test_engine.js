// const tests = [
//   ["(let x = 10; i < (y); (i++))", 1],
//   [")(let x = 10; i < (y); (i++))", 0],
//   ["(let x = 10; i < (y); (i++)", 0],
//   ["(let x = 10; i < ((y); (i++))", 0],
//   ["a bcd e f(", 0],
//   ["a bcd e f", 0],
// ];
/** 
 * @param tests - array of tupes of function argument and expected function result value
 */
exports.run_tests = function  (tests, tested_function) {
  let test_pass = 0;
  let test_fail = 0;
  for(let i = 0; i < tests.length; i++){
    if(tested_function(tests[i][0]) === tests[i][1] ){
      console.log("test pass\n");
      test_pass++;
    }
    else{
      console.log("test fail\n");
      test_fail++;
    } 
  }
  console.log({test_pass});
  console.log({test_fail});
}