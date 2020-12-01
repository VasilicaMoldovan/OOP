from model import *
def validateBaller(balla):
    errors=""
    if getId(balla)<0:
        errors+="invalid id!\n"
    if getName(balla)=="":
        errors+="invalid name!\n"
    if len(errors)>0:
        raise ValueError(errors)
