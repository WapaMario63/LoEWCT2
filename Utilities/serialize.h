#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <cstdint>
#include <QByteArray>
#include <QVector3D>
#include <QString>

#include "Utilities/DataType.h"

QByteArray doubleToData(double num);
QByteArray floatToData(float num);
float dataToFloat(QByteArray data);
QByteArray stringToData(QString str);
QString dataToString(QByteArray data);
QByteArray vectorToData(UVector vec);
UVector dataToVector(QByteArray data);
float dataToRangedSingle(float min, float max, int numberOfBits, QByteArray data);
QByteArray rangedSingleToData(float value, float min, float max, int numberOfBits);
QByteArray quaternionToData(UQuaternion quat);
uint8_t dataToUint8(QByteArray data);
uint16_t dataToUint16(QByteArray data);
uint32_t dataToUint32(QByteArray data);
unsigned getVUint32Size(QByteArray data);
QByteArray uint8ToData(uint8_t num);
QByteArray uint16ToData(uint16_t num);
QByteArray uint32ToData(uint32_t num);

// I don't know why I made these, but could be useful.

class RotationHelper
{
public:
    double DegreeToRadian(double angle);
    UQuaternion *EulToQuat2(UVector eu);
    UVector FromUQuat(UQuaternion q);
    float NormalizeAngle(float angle);
    UVector NormalizeAngles(UVector angles);
    UVector QuatToEul2(UQuaternion q);
    double RadianToDegree(double angle);
    UVector VecToDegrees(UVector v);
    UVector VecToRadian(UVector v);
    UQuaternion VecToUnityQuat(UVector v);
    UQuaternion VecToUnityQuat(float yaw, float pith, float roll); // We goin Ogre3D now?
};

#endif // SERIALIZE_H
