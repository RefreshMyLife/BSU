USE MilitaryUnit

--добавить альтернативносложущаего и удалить

INSERT INTO [Soldiers] (ID, [Name], Surname, RankID, FormOfServiceID)
VALUES (24, 'Дуб', 'Виктор', 1, 4)

SELECT *
FROM [Soldiers]

DELETE FROM [Soldiers]
WHERE FormOfServiceID = 4