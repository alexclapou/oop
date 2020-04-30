#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITY 2147483647

typedef struct{
    int x;
    int y;
}Point;

void input(char *text, Point points[], int *number_of_points);
float get_slope(float x1, float y1, float x2, float y2);
void init_point(Point *points, Point *point);
int points_already_found(Point *points_found, Point *point, int *number_of_points_found);
void reset_points_found(Point *points_found, Point *point, int *number_of_points_found);
void end_of_collinear_sequence(Point points_found[], Point points[], int *number_of_points_found, int *sequence_length, float *last_slope_found, int *new_end, int list_index, float actual_slope);
void initialize_last_slope(float *last_slope, Point points[], int *sequence_length, Point *point1, Point *point2, int list_index);
void check_collinear(Point *point1, Point *point2, float *actual_slope, float *last_slope_found, int *sequence_length, int *new_sequence_end, Point points[], int list_index);

int main()
{
    int index, temp_index, sequence_length, start_of_sequence, sequence_end, maximum_length, point_found, number_of_points, number_of_points_found;
    char input_text[1001];
    Point points[101], point1, point2, points_found[101];
    float slope, last_slope;

    index = 1;
    temp_index = 0;
    maximum_length = 0;
    number_of_points_found = 0;
    slope = -INFINITY;
    last_slope = -INFINITY;
    input(input_text, points, &number_of_points);
    point_found = points_already_found(points_found, &points[0], &number_of_points_found);

    while(index < number_of_points){
        point_found = points_already_found(points_found, &points[index], &number_of_points_found);

        if(point_found == 1)
            end_of_collinear_sequence(points_found, points, &number_of_points_found, &sequence_length, &last_slope, &temp_index, index, slope);
        else{
            if(last_slope == -INFINITY)
                initialize_last_slope(&last_slope, points, &sequence_length, &point1, &point2, index);
            else
                check_collinear(&point1, &point2, &slope, &last_slope, &sequence_length, &temp_index, points, index);
        }

        if(sequence_length > maximum_length){
            start_of_sequence = temp_index;
            maximum_length = sequence_length;
            sequence_end = index;
        }

        index++;
    }

    while(start_of_sequence <= sequence_end){
        printf("%d %d ", points[start_of_sequence].x, points[start_of_sequence].y);
        start_of_sequence++;
    }
}

void input(char *input_text, Point points[], int *number_of_points)
{
    char *coordinate;
    int number;

    scanf("%[^\n]s", input_text);
    coordinate = strtok(input_text, " ");
    *number_of_points = 0;
    while(coordinate != NULL){
        number = atoi(coordinate);
        points[*number_of_points].x = number;
        coordinate = strtok(NULL, " ");
        number = atoi(coordinate);
        points[*number_of_points].y = number;
        coordinate = strtok(NULL, " ");
        (*number_of_points)++;
    }
}

float get_slope(float Point1x, float Point1y, float Point2x, float Point2y)
{
    float delta_x, delta_y;

    delta_x = Point2x - Point1x;
    delta_y = Point2y - Point1y;
    if(delta_x == 0)
        return INFINITY;
    else
        return delta_y / delta_x;
}

void init_point(Point *points, Point *point)
{
    point->x = points->x;
    point->y = points->y;
}

int points_already_found(Point *points_found, Point *point, int *number_of_points_found)
{
    int index;

    index = 0;
    while(index < *number_of_points_found)
    {
        if(points_found[index].x == point->x && points_found[index].y == point->y)
            return 1;
        index++;
    }
    points_found[index].x = point->x;
    points_found[index].y = point->y;
    (*number_of_points_found)++;
    return 0;
}

void reset_points_found(Point *points_found, Point *point, int *number_of_points_found)
{
    points_found[0].x = point->x;
    points_found[0].y = point->y;
    *number_of_points_found = 0;
}


void end_of_collinear_sequence(Point points_found[], Point points[], int *number_of_points_found, int *sequence_length, float *last_slope_found, int *new_end, int list_index, float actual_slope)
{
    reset_points_found(points_found, &points[list_index], number_of_points_found);
    points_already_found(points_found, &points[list_index], number_of_points_found);
    *last_slope_found = actual_slope;
    *sequence_length = 1;
    (*new_end)++;
}
void initialize_last_slope(float *last_slope, Point points[], int *sequence_length, Point *point1, Point *point2, int list_index)
{
    init_point(&points[list_index-1], point1);
    init_point(&points[list_index], point2);
    *last_slope = get_slope(point1->x, point1->y, point2->x, point2->y);
    *sequence_length++;
}
void check_collinear(Point *point1, Point *point2, float *actual_slope, float *last_slope_found, int *sequence_length, int *new_sequence_end, Point points[], int list_index)
{
    init_point(&points[list_index-1], point1);
    init_point(&points[list_index], point2);
    *actual_slope = get_slope(point1->x, point1->y, point2->x, point2->y);
        if(*actual_slope == *last_slope_found)
            (*sequence_length)++;
        else{
            *last_slope_found = *actual_slope;
            *sequence_length = 1;
            *new_sequence_end = list_index-1;
        }
}
