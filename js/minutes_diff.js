let test_engine = require("./test_engine.js");

const tests1 = [
  ["12:33am-11:02pm", 811],
  ["12:34pm-12:33pm", 1],
  ["12:01am-00:10pm", 1431],
  ["10:34am-12:33pm", 601],
  ["01:34pm-12:33am", -1379],
];

function minute_diff(str){  
  const minutes = [];
  const re = /[01][0123456789]:[012345][0123456789][pa]m/g;
  const times = str.match(re);
  console.log({times});
  if(times === null) return -1;

  for(let i = 0; i < 2; i++){
    let time_tmp = 0;
    time_tmp +=  ( 
      parseInt( times[i].slice(0,2), 10 )  
      + ( (times[i][5] === 'p') ? 0 : 12 )        //caly ternary musi byc w nawiasie, bo + ma wyzszy priorytek od ?
    ) * 60;
    //console.log(time_tmp)
    time_tmp += parseInt( times[i].slice(3,5), 10);
    console.log(time_tmp);
    minutes.push(time_tmp);    
  }
  let minutes_difference = minutes[0]-minutes[1];
  return minutes_difference;
}

test_engine.run_tests(tests1, minute_diff);


