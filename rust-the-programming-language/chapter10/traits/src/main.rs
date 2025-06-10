// use aggregator::{SocialPost, Summary};
use aggregator::{NewsArticle, Summary};

fn main() {
    
    let article = NewsArticle {
        headline: String::from("headline"),
        location: String::from("location"),
        author: String::from("author"),
        content: String::from("content"),
    };

    println!("New article available! {}", article.summarize());



    // let post = SocialPost {
    //     username: String::from("Horse_ebook"),
    //     content: String::from("of course as you probably already know, people",),
    //     reply: false,
    //     repost: false,
    // };

    // println!("1 new social post: {}", post.summarize());
}
