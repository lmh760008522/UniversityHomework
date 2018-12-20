import turtle

def G(size,color,x,y,radius):
    turtle.pensize(size)
    turtle.color(color)
    turtle.penup()
    turtle.goto(x,y)
    turtle.pendown()
    turtle.circle(radius)

G(10,"blue",-110,-25,45)
G(10,"black",0,-25,45)
G(10,"red",110,-25,45)
G(10,"yellow",-55,-75,45)
G(10,"green",55,-75,45)
turtle.down()


