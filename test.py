import cv2
import pyzbar.pyzbar as pyzbar

font = cv2.FONT_HERSHEY_SIMPLEX

# 바코드 인식 및 테두리 설정
def read_frame(img):
    try:
        # 바코드 정보 decoding
        barcodes = pyzbar.decode(img)
        #바코드 여러개가 감지되면 오류 발생시키기
        if len(barcodes)>1:
            raise Exception("too many barcodes")
        barcode_info = barcodes[0].data.decode('utf-8')

        return barcode_info
    except Exception as e:
        print(e)

image = cv2.imread('D:\\pythonProjects\\bitdol_washingMachine\\barcode3.jpg', cv2.IMREAD_GRAYSCALE)
cv2.imshow("barcode reader", image)
print(read_frame(image))
cv2.waitKey(0)