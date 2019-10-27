//Language: Rust
//Author: Eric Loucks
//Github: http://github.com/EricBot89

use std::env;

fn main(){
    let args: Vec<String> = env::args().collect();
    let name = &args[1];
    println!("Hello {} this is Eric", name);
}