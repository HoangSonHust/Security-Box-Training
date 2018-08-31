from Controller import Controller
from LogInGUI import LogInGUI
class LogOutGUI(object):
	def RequestLogOut(self):
		contr = Controller
		logInGUI = LogInGUI
		userID=1
		contr.RequestLogOut(userID)


