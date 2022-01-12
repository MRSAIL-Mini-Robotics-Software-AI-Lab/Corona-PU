import sys

'''
The 3D renderer takes 2 arguments when you run the script
The first is the .obj file
The second is the name of the file to save the output in
'''


code = open(sys.argv[1], mode='r')  # the file which contains the code
code_lines = []


verts = []
lines = []
for line in code:
    line = line.split()
    if line[0] == 'v':
        verts.append([float(line[1]),float(line[2]),float(line[3])])

    elif line[0] == 'f':
        for l in range(1,len(line)-1):
            to_add = [int(line[l].split('/')[0]),int(line[l+1].split('/')[0])]
            to_add.sort()
            lines.append(to_add)

        to_add = [int(line[1].split('/')[0]),int(line[len(line)-1].split('/')[0])]
        to_add.sort()
        lines.append(to_add)
unique_lines = []
for l in lines:
    if l not in unique_lines:
        unique_lines.append(l)
lines = unique_lines
def point_create(val,x,y,z):
    x_str = x
    y_str = y
    z_str = z
    if x < 0:
        x_str = '0.0 - '+str(abs(x))
    if y < 0:
        y_str = '0.0 - '+str(abs(y))
    if z < 0:
        z_str = '0.0 - '+str(abs(z))
    return f'fvar points_{val}_x = {x_str} ;\nfvar points_{val}_y = {y_str} ;\nfvar points_{val}_z = {z_str} ;\nfvar projected_{val}_x = 0.0 ;\nfvar projected_{val}_y = 0.0 ;\n\n'


final_code = ''
template_1 = '@ 3D rotating cube\n\nivar background_color = 0 ;\nivar line_color = 17792 ;\n\n@ Add all points here\n\n'
final_code += template_1
for idx,v in enumerate(verts):
    to_add = point_create(idx,v[0],v[1],v[2])
    final_code += to_add
template_2 = '\n\nfvar width = 400.0 ;\nfvar height = 300.0 ;\nfvar half_screen_width = 200.0 ;\nfvar half_screen_height = 150.0 ;\nfvar temp1 = 0.0 ;\nfvar temp2 = 0.0 ;\nfvar temp3 = 0.0 ;\nfvar rotated_0 = 0.0 ;\nfvar rotated_1 = 0.0 ;\nfvar x1 = 0.0 ;\nfvar x2 = 0.0 ;\nfvar y1 = 0.0 ;\nfvar y2 = 0.0 ;\nfvar m1 = 0.0 ;\nfvar m2 = 0.0 ;\nfvar denom = 0.0 ;\nfvar b1 = 0.0 ;\nfvar b2 = 0.0 ;\nfvar s = 0.0 ;\nfvar c = 0.0 ;\nfvar g = 0.0 ;\nbvar background_y = 1 ;\nbvar background_x = 1 ;\nfvar counter_x = 0.0 ;\nfvar counter_y = 0.0 ;\nfvar counter_l = 0.0 ;\nfvar new_x = 0.0 ;\nfvar new_y = 0.0 ;\nfvar new_z = 0.0 ;\nbvar t = 0 ;\nfvar x_point = 0.0 ;\nfvar y_point = 0.0 ;\nbvar line_l = 1 ;\nfvar theta = 0.03 ;\nbvar draw_loop = 1 ;\nfvar focal_length = 75.0 ;\ns = sin theta ;\nc = cos theta ;\ns = 0.15643 ;\nc = 0.9877 ;\n\ng = 0.0 - s ;\nwhile draw_loop {\n\n  @ Rotating and projecting to camera view\n\n\n'
final_code += template_2


for i in range(len(verts)):
    val = i
    to_add =  f'@ points {val}\n  temp1 = points_{val}_x * c ;\n  temp3 = points_{val}_z * s ;\n  rotated_0 = temp1 + temp3 ;\n  new_x = rotated_0 ;\n  rotated_0 = rotated_0 * focal_length ;\n  projected_{val}_x = rotated_0 + half_screen_width ;\n\n  rotated_1 = points_{val}_y ;\n  new_y = rotated_1 ;\n  rotated_1 = rotated_1 * focal_length ;\n  projected_{val}_y = rotated_1 + half_screen_height ;\n\n  temp1 = points_{val}_x * g ;\n  temp3 = points_{val}_z * c ;\n  new_z = temp1 + temp3 ;\n  points_{val}_x = new_x ;\n  points_{val}_y = new_y ;\n  points_{val}_z = new_z ;\n\n'
    final_code += to_add

template_4 = '\n  @ Draw Background\n  background_y = 1 ;\n  background_x = 1 ;\n  counter_x = 0.0 ;\n  counter_y = 0.0 ;\n  while background_y {\n    background_x = 1 ;\n    counter_x = 0.0 ;\n\n    while background_x {\n      @ Draw background pixel\n      intf counter_y ;\n      intf counter_x ;\n      VRAM_Save counter_y counter_x background_color ;\n      fint counter_y ;\n      fint counter_x ;\n      counter_x = counter_x + 1.0 ;\n      background_x = counter_x < width ;\n    }\n\n    counter_y = counter_y + 1.0 ;\n    background_y = counter_y < height ;\n  }\n\n'
final_code += template_4

for l in lines:
    to_add = f'@ line {l[0]-1}, {l[1]-1}\n  x1 = projected_{l[0]-1}_x ;\n  x2 = projected_{l[1]-1}_x ;\n  y1 = projected_{l[0]-1}_y ;\n  y2 = projected_{l[1]-1}_y ;\n  m1 = x2 - x1 ;\n  m2 = y2 - y1 ;\n  m1 = m1 '
    to_add_2 = f' 100.0 ;\n  m2 = m2 '
    to_add_3 = ' 100.0 ;\n  t = m1 == 0.0 ;\n  if t {\n    m1 = 0.001 ;\n  } else{\n\n  }\n\n  t = m2 == 0.0 ;\n  if t {\n    m2 = 0.001 ;\n  } else{\n\n  }\n  b1 = x1 ;\n  b2 = y1 ;\n  counter_l = 0.0 ;\n  y_point = 0.0 ;\n  x_point = 0.0 ;\n  line_l = 1 ;\n  while line_l {\n\n    y_point = m2 * counter_l ;\n    y_point = y_point + b2 ;\n\n    x_point = m1 * counter_l ;\n    x_point = x_point + b1 ;\n    @ Draw point\n\n    intf y_point ;\n    intf x_point ;\n    VRAM_Save y_point x_point line_color ;\n    fint y_point ;\n    fint x_point ;\n    counter_l = counter_l + 0.1 ;\n    line_l = counter_l < 100.0 ;\n  }\n\n'
    final_code += to_add+'/'+to_add_2+'/'+to_add_3
template_3 = 'Idle ;\n}\n'
final_code += template_3
output_file = sys.argv[2]
new_bemo_code = open(f"{output_file}", mode='w+')
new_bemo_code.write(final_code)
