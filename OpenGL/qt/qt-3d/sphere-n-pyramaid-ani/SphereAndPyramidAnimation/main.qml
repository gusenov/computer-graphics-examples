import QtQuick 2.14
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import QtQuick.Scene3D 2.0

Rectangle {
    color: 'black'  // фон черного цвета

    Scene3D {  // элемент трехмерной сцены
        
        anchors.fill: parent  // делаем так, чтобы он заполнил всю его область
        
        focus: true  // для того чтобы сцена гарантированно получала ввод пользователя
        
        // а для того чтобы сцена могла его интерпретировать,
        // присваиваем свойству aspects массив из двух значений: "input" и "logic"
        aspects: ["input", "logic"]
        
        // не хотим,
        // чтобы в случае изменения размеров окна при отображении происходило искажение
        // объектов сцены
        cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

        Entity {  // элемент сущности, который объединяет в себе все элементы трехмерной сцены:

            Camera {  // Камера
                id: camera
                nearPlane : 0.1  // значения ближнего 
                farPlane : 1000.0  // и дальнего фокусных расстояний
                position: Qt.vector3d(0.0, 0.0, 150.0)  // помещаем камеру на 50 единиц от начала положения координат вдоль оси Z
            }

            FirstPersonCameraController {  // Управление положением камеры
                // уникальный идентификатор нашей камеры, чтобы дать возможность пользователям
                // управлять созданной камерой при помощи мыши, курсоров, тачпада, сенсорного экрана и т. п.;
                camera: camera
                
                linearSpeed: 1000.0
                acceleration: 0.1
                deceleration: 1.0
            }

            components: [  // объединяет в сущности сцены настройки рендеринга с пользовательским вводом
                RenderSettings {  // Рендеринг - это процесс создания двумерного изображения из трехмерной сцены.
                    activeFrameGraph:
                        ForwardRenderer {
                            camera: camera  // Для осуществления рендеринга необходима камера
                            
                            // Для того чтобы был виден черный цвет фона главного элемента окна Rectange, мы делаем цвет очистки прозрачным
                            clearColor: "transparent"
                        }
                },
                InputSettings { }
            ]

            // задает направленный источник света
            DirectionalLight {  // Свет
                color: "#afafff"  // со слегка голубоватым оттенком
            }

            Entity {
                PhongMaterial { //Материал
                    id: phongMaterial
                    ambient: Qt.rgba( 0.3, 0.3, 0.3, 1.0 )
                    diffuse: Qt.rgba( 1, 1, 1, )
                }

                SphereMesh { //Геометрия объекта сферы
                    id: sphereMesh
                    radius: 6
                }

                Transform { //Изменения положения объекта сферы
                    id: sphereTransform
                    
                    // для управления углом поворота сферы мы создаем свойство
                    property real myParam: 0
                    
                    // формируем трансформационную матрицу
                    matrix: {
                        var mat = Qt.matrix4x4();
                        mat.rotate(myParam,        // этот угол поворота будет управляться свойством myParam.
                            Qt.vector3d(0, 1, 0))  // ось, вокруг которой будет осуществляться вращение.
                        // Оси указываются в порядке: Х, У и Z - у нас только второй параметр
                        // равен 1, все остальные равны 0, следовательно, объект сферы будет вращаться по оси У.
                        
                        // Для того чтобы вращение происходило на удалении, мы производим в трансформационной матрице смещение.
                        mat.translate(Qt.vector3d(24, 0, 0));  
                        
                        return mat;
                    }
                }

                components: [sphereMesh, phongMaterial, sphereTransform]
                NumberAnimation { //Анимация объекта сферы
                    target: sphereTransform  // в качестве уникального идентификатора целевого объекта
                    property: "myParam"  // будем изменять значения свойства myParam
                    duration: 10000  // продолжительность цикла анимации
                    from: 0  // начальное
                    to: 360  // и конечное значения угла поворота (О и 360 градусов), который должен изменяться за каждый цикл
                    loops: Animation.Infinite  // для того чтобы анимация повторялась бесконечно
                    running: true  // Процесс запуска анимации происходит присвоением свойству running значения true.
                }
            }

            Entity {
                GoochMaterial {//Материал
                    id: goochМaterial
                    diffuse: Qt.rgba( 1, 1, 1, 1 )
                }

                Mesh { //Геометрия объекта пирамиды
                    id: pyrarnidМesh
                    source: "qrc:/pyramid.obj"
                }

                Transform { // Повороты объекта пирамиды
                    id: pyrarnidTransform
                    
                    // угол поворота будет управляться при помощи свойства
                    property real myRotation: 0
                    
                    // формируем трансформационную матрицу
                    matrix: {
                        var mat = Qt.matrix4x4();
                        mat.rotate(myRotation, 
                            Qt.vector3d(1, 1, 1))  // для того чтобы поворот осуществлялся по всем трем осям, 
                                                   // передаем вторым параметром объект vectorЗd, 
                                                   // в котором все три значения устанавливаем равными 1.
                        mat.scale(Qt.vector3d(10, 10, 10) );  // размер
                        return mat;
                    }
                }
                components: [pyrarnidМesh, goochМaterial, pyrarnidTransform]
                NumberAnimation { //Анимация объекта пирамиды
                    target: pyrarnidTransform
                    property: "myRotation"
                    duration: 10000
                    from: 0
                    to: 360
                    loops: Animation.Infinite
                    running: true
                }
            }

        }
    }
}

