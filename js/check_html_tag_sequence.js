let test_engine = require("./test_engine.js");

const tests = [
  ["<p></p><div><b></b></div>", "true"],
  ["<p></i><div><b></b></div>", "</i>"],
  ["<p></p><div><i></b></div>", "</b>"],
  ["<p></p><div></b></div>", "</b>"],
  ["<p></p><div><b></div>", "</div>"],
  ["<p></p><div><b></b></div><div><div><b><i></b></b></div></div>", "</b>"],
]

/* helper functions */

function is_close_tag(str){
  if( str[1]=='\/') return true;
  return false;
}

function is_complementar2(tag1, tag2){
  if(! is_close_tag(tag2)) return false;
  if(tag2.slice(2,) === tag1.slice(1,)) return true;
  return false;
}



/* iterative version */

function check_html_tag_sequence(str){
  let wrong_tag = "true";

  const re = /(\<[\/]?p\>)|(\<[\/]?b\>)|(\<[\/]?i\>)|(\<[\/]?div\>)/g

  const html_tags = str.match(re);  
  console.log({html_tags});
  if(html_tags === null)
    return result;
  //html_tags.forEach((val) => console.log(val, "  - ", is_close_tag(val) ? " close" : " open"))
 
  let found_wrong_tag = false;
  const curr = [];
  let level = -1;
  for(let i = 0; i < html_tags.length && !found_wrong_tag ; i++){
    if(! is_close_tag(html_tags[i])){
      level++;
      if(curr.length < level + 1) 
        curr.push(i)   
      else
        curr[level] = i;      
    }
    else {      
      if( is_complementar2(html_tags[curr[level]], html_tags[i]) ){
        level--;        
      }
      else {
        found_wrong_tag = true;
        wrong_tag = html_tags[i];
      } //!is_complementar2
    } //is_close_tag    
  } //for
  console.log({wrong_tag});
  
  return wrong_tag;
}



/* recursive version */

function search_one_level(idx, html_tags){
  let level_first_tag_idx = idx;
  const res = {
    returing_tag:"true",
    idx: idx,
  }  
    
  if( !is_close_tag(html_tags[idx]) ){
    let r1;
    while( idx + 1 < html_tags.length){      
      r1 = search_one_level(idx + 1, html_tags);
      if(r1.returing_tag == "true"){ //next level closed properly
        idx = r1.idx + 1;
      }            
      else {
        break;
      }
    }    
    res.returing_tag = r1.returing_tag;
    res.idx = r1.idx;
    return res;
  }
  else {    
    if( is_complementar2(  (idx >= 0 ? html_tags[idx - 1] : ""), html_tags[idx])) {  //correct closing tag
      res.returing_tag = "true";    
      res.idx = idx;
    }
    else { //incorrect tag
      res.returing_tag = html_tags[idx];
      res.idx = idx;
    }
    return res;
  }
}

function check_html_tag_sequence_requrr(str){
  let wrong_tag = "true";

  const re = /(\<[\/]?p\>)|(\<[\/]?b\>)|(\<[\/]?i\>)|(\<[\/]?div\>)/g

  const html_tags = str.match(re);  
  console.log({html_tags});
  if(html_tags === null)
    return result;
  //html_tags.forEach((val) => console.log(val, "  - ", is_close_tag(val) ? " close" : " open"))
 
  wrong_tag = search_one_level(0, html_tags);
  
  console.log({wrong_tag});  
  return wrong_tag;
}



/* tests */

test_engine.run_tests(tests, check_html_tag_sequence);
test_engine.run_tests(tests, check_html_tag_sequence_requrr);
