void setup(){
  size(800,800);
  
}

int Xpos=0,Ypos=0;

void draw(){
  
  noFill();
  
  background(125);
  
  fill(#5D6712);
  
  rect(Xpos,Ypos,10,10);
  
}

void keyPressed(){
  if(key=='w'){
    Ypos-=5;
  }
  if(key=='s'){
    Ypos+=5;
  }
  if(key=='a'){
    Xpos-=5;
  }
  if(key=='d'){
    Xpos+=5;
  }
}
