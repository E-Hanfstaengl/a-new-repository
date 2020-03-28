PImage china;
PImage england;
PImage america;
PImage franch;
PImage germany;
PImage japan;
int dateC;
int dateE;
int dateA;
int dateF;
int dateG;
int dateJ;

void setup()
{
  size(1200,800);
  china = loadImage("china.jpg");
  england = loadImage("england.jpg");
  america = loadImage("america.jpg");
  franch = loadImage("franch.jpg");
  germany = loadImage("germany.jpg");
  japan = loadImage("japan.jpg"); 
  dateC = 500;
  dateE = 10000;
  dateA = 5000000;
  dateF = 30000;
  dateG = 50000;
  dateJ = 40000;
}

void draw()
{
  background(211,227,240);
  image(china,50,50,300,200);
  image(america,450,50,300,200);
  image(england,850,50,300,200);
  image(franch,50,450,300,200);
  image(germany,450,450,300,200);
  image(japan,850,450,300,200);
}

void mousePressed()
{
  if( mouseX > 50 && mouseX < 350 && mouseY > 50 && mouseY < 250)
  {
    println (dateC);
  }
  if( mouseX > 450 && mouseX < 750 && mouseY > 50 && mouseY < 250)
  {
    println (dateA);
  }
  if( mouseX > 850 && mouseX < 1150 && mouseY > 50 && mouseY < 250)
  {
    println (dateE);
  }
  if( mouseX > 50 && mouseX < 350 && mouseY > 450 && mouseY < 650)
  {
    println (dateF);
  }
  if( mouseX > 450 && mouseX < 750 && mouseY > 450 && mouseY < 650)
  {
    println (dateG);
  }
  if( mouseX > 850 && mouseX < 1150 && mouseY > 450 && mouseY < 650)
  {
    println (dateJ);
  }
  
}
