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

function check_level(level, idx, html_tags){
  let level_first_tag = html_tags[idx];  
  if(idx + 1 < html_tags.length){
    if(is_close_tag(html_tags[idx + 1])){
      return -2; //open missing
    }
    if(is_complementar2(level_first_tag, html_tags[idx + 1])){
      return -1; //ok
    }
    else{
      let result = check_html_tag_sequence(level + 1, idx + 1, html_tags);
      if(result === -1) 
        return result;
      else {
        if(){

        }
      }
    }
  }
  else {
    return level; //
  }
}

function check_html_tag_sequence(str){
  let result = "true";

  const re = /(\<[\/]?p\>)|(\<[\/]?b\>)|(\<[\/]?i\>)|(\<[\/]?div\>)/g

  const html_tags = str.match(re);  
  console.log({html_tags});
  if(html_tags === null)
    return result;
  //html_tags.forEach((val) => console.log(val, "  - ", is_close_tag(val) ? " close" : " open"))
  let nesting_level = 0;
  for(let i = 0; i < html_tags.length; i++){
    if( is_close_tag( html_tags[i] ) )
      nesting_level++;
    else
      nesting_level--;        
  }
  if(nesting_level)

  return result;
}



test_engine.run_tests(tests, check_html_tag_sequence);