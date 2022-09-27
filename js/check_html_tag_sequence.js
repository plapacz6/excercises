let test_engine = require("./test_engine.js");

const tests = [
  ["<p></p><div><b></b></div>", "true"],
  ["<p></i><div><b></b></div>", "</i>"],
  ["<p></p><div><i></b></div>", "</b>"],
  ["<p></p><div></b></div>", "</div>"],
  ["<p></p><div><b></div>", "</div>"],
]

function is_close_tag(str){
  if( str[1]=='\/') return true;
  return false;
}
function is_complementar2(tag1, tag2){
  if(! is_close_tag(tag2)) return false;
  if(tag2.slice(2,) === tag1) return true;
  return false;
}



function check_html_tag_sequence(str){
  let wrong_tag = "true";

  const re = /(\<[\/]?p\>)|(\<[\/]?b\>)|(\<[\/]?i\>)|(\<[\/]?div\>)/g

  const html_tags = str.match(re);  
  console.log({html_tags});
  if(html_tags === null)
    return result;
  //html_tags.forEach((val) => console.log(val, "  - ", is_close_tag(val) ? " close" : " open"))
 
  let nesting_indicator = "----------->";

  
  let found_wrond_tag = false;
  const curr = [];
  let level = -1;
  for(let i = 0; i < html_tags.length && !found_wrond_tag ; i++){
    if(! is_close_tag(html_tags[i])){
      level++;
      if(curr.length < level + 1) curr.push(i);      
      console.log( nesting_indicator.slice(-level,));      
    }
    else {
      if( is_complementar2(html_tags[curr[level]], html_tags[i]) ){
        level--;        
      }
      else {
        found_wrond_tag = true;
        wrong_tag = html_tags[i];
      } //!is_complementar2
    } //is_close_tag    
  } //for
  console.log({wrong_tag});
  return wrong_tag;
}



test_engine.run_tests(tests, check_html_tag_sequence);
