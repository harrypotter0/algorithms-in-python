import java.util.Scanner;

public class BombDrop
{
    private static class Point
    {
        float x;
        float y;

        Point(float x, float y)
        {
            this.x = x;
            this.y = y;
        }

        float distance(Point p2)
        {
            float dx, dy;

            dx = (x - p2.x);
            dy = (y - p2.y);

            return (float) Math.sqrt((dx * dx) + (dy * dy));
        }
    }

    private static class Line
    {
        Point p1;
        Point p2;

        Line(Point p1, Point p2)
        {
            this.p1 = p1;
            this.p2 = p2;
        }

        float length()
        {
            return p1.distance(p2);
        }
    }

    private static class Circle
    {
        float r;
        Point center;

        Circle(int r, int x, int y)
        {
            this.r = r;
            this.center = new Point(x, y);
        }

        boolean intersects(Point point)
        {
            return point.distance(center) <= r;
        }

        float intersectionDistance(Point point)
        {
            return r - point.distance(center);
        }
    }

    private static float processLine(Line line, Circle circle)
    {
        boolean p1intersects = circle.intersects(line.p1);
        boolean p2intersects = circle.intersects(line.p2);

        if (!p1intersects && !p2intersects)
            return line.length();

        if (p1intersects && p2intersects)
            return 0;

        float distance = line.length();

        if (p1intersects)
            distance -= circle.intersectionDistance(line.p1);

        else if (p2intersects)
            distance -= circle.intersectionDistance(line.p2);

        return distance;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Circle circle = new Circle(sc.nextInt(), sc.nextInt(), sc.nextInt());
        Line[] lines = new Line[n];

        for (int i = 0; i < n; i++)
        {
            Point p1 = new Point(sc.nextInt(), sc.nextInt());
            Point p2 = new Point(sc.nextInt(), sc.nextInt());

            lines[i] = new Line(p1, p2);
        }

        float count = 0;

        for (int i = 0; i < n; i++)
            count += processLine(lines[i], circle);

        System.out.printf("%.2f\n", count);

        sc.close();
    }
}
