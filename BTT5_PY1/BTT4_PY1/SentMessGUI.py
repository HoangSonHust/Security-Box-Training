from Controller import Controller
from msvcrt import getch
class SentMessGUI(object):
	def RequestSentMess(userID):
		controller = Controller
		print("have 2 ways to sent mess, press ctr+A to sent to friend you want to input or press ctr+L to view friend list")
		input_key = ord(getch())    # Hàm getch() sẽ nhận dạng phím mà bạn ấn vào và hàm ord() sẽ chuyển nó về mã ASCII
		if(input_key==1):
			print("input friendName that you want to sent mess: ")
			friendName= input()
			print("input mess: ")
			mess= input()
			controller.RequestSentMess(userID,controller.TakeUserID(friendName), mess )
		if(input_key==12):
			print("meo")
			for row in controller.TakeFriendListToSentMess(userID):
				print(row)
			print("input friend's position to sent mess: ")
			position= input()
			print("input mess: ")
			mess= input()
			controller.RequestSentMess(userID,controller.TakeUserIDByPosition(userID, position), mess )

